#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{ 
  char c;
  char str[10];

  c = 'X';
  if (fork()) {		// recall 0 in C is FALSE
    // Parent != 0
    c = 'F';
    strcpy (str, "father");
    sleep (5);
  } else {
    // Child
    strcpy (str, "child");
  }

  fprintf(stdout, "PID=%d; PPID=%d; c=%c; str=%s\n",
          getpid(), getppid(), c, str);

  exit(0);
}