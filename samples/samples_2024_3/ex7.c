#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void p1_signal(int sig){
    printf("SIG1\n");
    return;
}
void p2_signal(int sig){
    printf("SIG2\n");
    return;
}

int main(){
    signal(SIGUSR1, p1_signal);
    signal(SIGUSR2,p2_signal);

    fflush(stdout);
    int fd[2];
    if(pipe(fd) == -1){
        printf("Something is wrong with pipe\n");
        fflush(stdout);
        exit(1);
    }

    int id = fork();

    if(id == 0){    
        //child
        int waitsts = pause();
        char str[100];
        close(fd[0]);
        printf("Enter a word:");
        fflush(stdout);
        scanf("%s", str);
        write(fd[1], str ,strlen(str)+1);
        kill(getppid(),SIGUSR2);
        close(fd[1]);
        return waitsts;

    }else{
        //parent
        sleep(1);
        kill(id, SIGUSR1);
        int waitsts = pause();
        char str[100];
        close(fd[1]);
        read(fd[0], str, strlen(str)+1);
        printf("%s\n", str);
        close(fd[0]);
        return waitsts;
    }

    return 0;
}