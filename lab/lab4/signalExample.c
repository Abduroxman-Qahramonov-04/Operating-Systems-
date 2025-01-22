#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig){
    return;
}

int main(){
    signal(SIGUSR1, handle_signal); // it does not call a signal, instead it receives the signal
    int id = fork();

    if(id == 0){
        while(1){
            pause();
            printf("Child woke up!!! -%d\n",getpid());
            sleep(1);
            kill(getppid(),SIGUSR1);
        }
    }else{    
        while(1){
            printf("Parent woke up!!! -%d\n",getpid());
            sleep(1);
            kill(id,SIGUSR1);
            pause();
        }
    }

    //kill(SIGINT,getpid());
    return 0;
}