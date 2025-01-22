#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

typedef struct semaphore{
    int fd[2];
}semaphore_t;

int semaphore_init(semaphore_t* sem, int value){
    if(pipe(sem->fd) == -1){
        printf("Something wrong with pipe\n");
        exit(1);
    }
    for(int i = 0; i<value; i++)
        write(sem->fd[1], "x", 1);
    return 0;
}
void semaphore_wait(semaphore_t* sem){
    char token;
    read(sem->fd[0],&token, 1);
}
void semaphore_signal(semaphore_t* sem){
    write(sem->fd[1],"x",1);
}
void semaphore_destroy(semaphore_t* sem){
    close(sem->fd[0]);
    close(sem->fd[1]);
}

void pA(){

}
void pB(){

}
void pC(){

}
void pD(){

}
void pE(){

}
void pF(){

}
void pG(){

}
void pH(){

}
void pI(){

}

int main(){
    int pIDA,pIDB,pIDC,pIDD, pIDE,pIDF,pIDG,pIDH;
    while(1) {
    pIDA=fork();
    if (pIDA!=0) {
       pIDB=fork();
       if (pIDB!=0) {
         pIDC=fork(); 
         if (pIDC!=0) {
              pIDD=fork();
              if (pIDD!=0) {
                  pIDH=fork();
                  if (pIDH!=0) {
                      pI();
                    } else
                      pH();    
               } else
                pD();   
           }else {
                pIDE=fork();
                if (pIDE!=0)
                   pC();
                else {
                      pIDF=fork();
                      if (pIDF!=0) {
                         pE();  
                       } else {
                            pIDG=fork();
                            if (pIDG!=0)  
                                pF();
                            else pG(); 
                          }     
                   }   
            }   
          }else
            pB();                        
    }else pA();
  }
    return 0;
}