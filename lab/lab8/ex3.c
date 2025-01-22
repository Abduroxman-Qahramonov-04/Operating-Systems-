#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>

#define THREAD_NUM 9

pthread_t tA,tB,tC,tD,tE,tF,tG,tH,tI;
sem_t semA,semBCD,semEF,semG,semH,semI;

void* routineA(void* arg){
    sem_wait(&semA);
    printf("A\n");
    sleep(2);
    sem_post(&semBCD);
    sem_post(&semBCD);
    sem_post(&semBCD);
}
void* routineB(void* arg){
    sem_wait(&semBCD);
    sleep(2);
    printf("B\n");
}
void* routineC(void* arg){
    sem_wait(&semBCD);
    sleep(2);
    printf("C\n");
}
void* routineD(void* arg){
    sem_wait(&semBCD);
    sleep(2);
    printf("D\n");
    sem_post(&semEF);
    sem_post(&semEF);
}
void* routineE(void* arg){
    sem_wait(&semEF);
    printf("E\n");
    sleep(2);
}
void* routineF(void* arg){
    sem_wait(&semEF);
    sleep(2);
    printf("F\n");
    sem_post(&semH);
    sem_post(&semG);
}
void* routineG(void* arg){
    sem_wait(&semG);
    sleep(2);
    printf("G\n");
    sem_post(&semI);

}
void* routineH(void* arg){
    sem_wait(&semH);
    sleep(2);
    printf("H\n");
}
void routineI(){
    sem_wait(&semI);
    printf("I\n");
    sleep(20);
    sem_post(&semA);
}

int main(){
    sem_init(&semA,0,1);
    sem_init(&semBCD,0,0);
    sem_init(&semEF,0,0);
    sem_init(&semH,0,0);
    sem_init(&semG,0,0);
    sem_init(&semI,0,0);
   
    while(1){
        pthread_create(&tA, NULL, &routineA, NULL);
        pthread_create(&tB, NULL, &routineB, NULL);
        pthread_create(&tC, NULL, &routineC, NULL);
        pthread_create(&tD, NULL, &routineD, NULL);
        pthread_create(&tE, NULL, &routineE, NULL);
        pthread_create(&tF, NULL, &routineF, NULL);
        pthread_create(&tG, NULL, &routineG, NULL);
        pthread_create(&tH, NULL, &routineH, NULL);
        routineI();
    } 

    sem_destroy(&semA);
    sem_destroy(&semBCD);
    sem_destroy(&semEF);
    sem_destroy(&semG);
    sem_destroy(&semH);
    sem_destroy(&semI);


    return 0;
}
