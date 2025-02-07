#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct thread_data{
    int n;
    int result;
}thread_data_t;


void* fibonacci(void* arv){
    thread_data_t* data = arv;
    int n = data->n;
    if(n<2){
        data->result = n;
        return NULL;
    }
    pthread_t p1,p2;

    thread_data_t* left = malloc(sizeof(thread_data_t));
    thread_data_t* right = malloc(sizeof(thread_data_t));
    left->n = n - 1;
    left->result = 0;
    right->n = n - 2;
    right->result = 0;


    pthread_create(&p1, NULL, &fibonacci, left);
    pthread_create(&p2, NULL, &fibonacci, right);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);


    data->result = left->result+right->result;
    return NULL;
}

int main(){
    thread_data_t* data = malloc(sizeof(thread_data_t));
    int n = 7;
    if(n<1){
        return 1;
    }
    data->n = n;
    data->result = 0;
    fibonacci(data);

    printf("Res=%d", data->result);
    return 0;
}