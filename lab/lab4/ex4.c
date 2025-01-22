#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void handle_signal(int sig){
    return;
}
int main(){
    signal(SIGUSR1,handle_signal);
    int id = fork();
    if(id == 0){
        while(1){
            //consumer
            pause();
            FILE* fp = fopen("temp.txt","r");
            int sibling_id;
            char text[50];
            fscanf(fp, "%s %d", text,&sibling_id);
            fclose(fp);
            printf("%s\n", text);
            kill(sibling_id,SIGUSR1);
        }

    }else{
        int second_id = fork();
        if(second_id == 0){
            //producer  
            char text[50];
            do{
                printf("Enter a word:");
                scanf("%s",text);
                FILE* fp = fopen("temp.txt","w");
                fprintf(fp,"%s %d",text,getpid());
                fclose(fp);
                kill(id,SIGUSR1);
                pause();

            }while(strcmp(text,"end")!=0);
        }else{
            wait(NULL);
            wait(NULL);
            exit(0);
        }
    }


    return 0;
}