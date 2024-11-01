#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    fprintf (stdout, "#1: PID=%d; My parent PID=%d\n",
    getpid(), getppid());

  fork();

  // If processes sleep they can be seen with command ps ...
  sleep (3);

  fprintf (stdout, "#2: PID=%d; My parent PID=%d\n",
           getpid(), getppid());
   fork();
    sleep(3);
  fprintf (stdout, "#3: PID=%d; My parent PID=%d\n",
           getpid(), getppid());
  return (1);
}