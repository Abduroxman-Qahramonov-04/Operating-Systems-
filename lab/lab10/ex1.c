#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>


sem_t semAB,semC,semD;
pthread_t pA,pB,pC,pD;

void* fnA(){
    while(1){
        sem_wait(&semAB);
        printf("A\n");
        sem_post(&semC);
    }   
}
void* fnB(){
    while(1){
        sem_wait(&semAB);
        printf("B\n");
        sem_post(&semC);
    }
    
}
void* fnC(){
    while(1){
        sem_wait(&semC);
        printf("C\n");
        sem_post(&semD);
    }
    
}
void* fnD(){
    while(1){
        sem_wait(&semD);
        printf("D\n");
        sleep(2);
        sem_post(&semAB);
    }
    
}

int main(){
    sem_init(&semAB, 0, 1);
    sem_init(&semC, 0, 0);
    sem_init(&semD, 0, 0);

    pthread_create(&pA, NULL, &fnA, NULL);
    pthread_create(&pB, NULL, &fnB, NULL);
    pthread_create(&pC, NULL, &fnC, NULL);
    pthread_create(&pD, NULL, &fnD, NULL);

    pthread_join(pA,NULL);
    pthread_join(pB,NULL);
    pthread_join(pC,NULL);
    pthread_join(pD,NULL);


    sem_destroy(&semAB);
    sem_destroy(&semC);
    sem_destroy(&semD);    
    return 0;
}