#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>

#define THREAD_NUM 9

pthread_t tA,tB,tC,tD,tE,tF,tG,tH,tI;
sem_t semA,semB,semC,semD,semE,semF,semG,semH,semI;

void* routineA(void* arg){
    while(1){
        sem_wait(&semA);
        printf("A\n");
        sleep(2);
        sem_post(&semB);
        sem_post(&semC);
        sem_post(&semD);
    }
}
void* routineB(void* arg){
    while(1){
        sem_wait(&semB);
        sleep(2);
        printf("B\n");
    }
}
void* routineC(void* arg){
    while(1){
        sem_wait(&semC);
        sleep(2);
        printf("C\n");
    }
}
void* routineD(void* arg){
    while(1){
        sem_wait(&semD);
        sleep(2);
        printf("D\n");
        sem_post(&semE);
        sem_post(&semF);
    }
}
void* routineE(void* arg){
    while(1){
        sem_wait(&semE);
        sleep(2);
        printf("E\n");
    }
}
void* routineF(void* arg){
    while(1){
        sem_wait(&semF);
        sleep(2);
        printf("F\n");
        sem_post(&semH);
        sem_post(&semG);
    }
}
void* routineG(void* arg){
    while(1){
        sem_wait(&semG);
        sleep(2);
        printf("G\n");
        sem_post(&semI);
    }

}
void* routineH(void* arg){
    while(1){
        sem_wait(&semH);
        sleep(2);
        printf("H\n");
    }
}
void routineI(){
    while(1){
        sem_wait(&semI);
        printf("I\n");
        sleep(20);
        sem_post(&semA);
    }
}

int main(){
    sem_init(&semA,0,1);
    sem_init(&semB,0,0);
    sem_init(&semC,0,0);
    sem_init(&semD,0,0);
    sem_init(&semE,0,0);
    sem_init(&semF,0,0);
    sem_init(&semH,0,0);
    sem_init(&semG,0,0);
    sem_init(&semI,0,0);
   
    
    pthread_create(&tA, NULL, &routineA, NULL);
    pthread_create(&tB, NULL, &routineB, NULL);
    pthread_create(&tC, NULL, &routineC, NULL);
    pthread_create(&tD, NULL, &routineD, NULL);
    pthread_create(&tE, NULL, &routineE, NULL);
    pthread_create(&tF, NULL, &routineF, NULL);
    pthread_create(&tG, NULL, &routineG, NULL);
    pthread_create(&tH, NULL, &routineH, NULL);
    routineI();
    
    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);
    sem_destroy(&semD);
    sem_destroy(&semE);
    sem_destroy(&semF);
    sem_destroy(&semG);
    sem_destroy(&semH);
    sem_destroy(&semI);

    return 0;
}
