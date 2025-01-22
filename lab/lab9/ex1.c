#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define LEN 100

pthread_t p1,p2,p3;
sem_t s1,s2,s3;

char row[LEN + 1];
int flag = 1;

void* routine1(void* arg){
    FILE* fp = fopen("file.txt", "r");
    while(fgets(row, LEN, fp)!=NULL){
        sem_wait(&s1);
        printf("Thread 1 read the line -:\n%s\n", row);
        sem_post(&s2);
        sem_wait(&s1);
    }
    printf("Thread one finished\n");
    fclose(fp);
    sem_post(&s2);
    sem_post(&s3);
    flag = 0; 
}
void* routine2(void* arg){
    while(1){
        sem_wait(&s2);
        if(flag){
            row[0] = 'A';
            row[1] = 'B';
            row[2] = 'C';
            printf("Thread 2 swapped chars -:\n%s\n", row);
            sem_post(&s3);
        }else break;   
    }
    printf("Thread 2 finished\n");
}
void* routine3(void* arg){ 
    FILE* fp = fopen("output.txt", "a");
    if(fp == NULL){
        printf("Could not open the file\n");
        exit(1);
    }
    while(1){
        if(flag){
            sem_wait(&s3);
            printf("Thread 3 saving output file\n");
            printf("%s\n", row);
            fprintf(fp, "%s", row);
            fflush(fp);
            sem_post(&s1);
            sem_post(&s1);
        }else break;

    }
    fclose(fp);
    printf("Thread 3 finished\n");
}

int main(int argc, char* argv[]){
    sem_init(&s1,0,1);
    sem_init(&s2,0,0);
    sem_init(&s3,0,0);

    pthread_create(&p1, NULL, &routine1, NULL);
    pthread_create(&p2, NULL, &routine2, NULL);
    pthread_create(&p3, NULL, &routine3, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(p3, NULL);


    sem_destroy(&s1);
    sem_destroy(&s2);
    sem_destroy(&s3);

    pthread_exit(0);
}