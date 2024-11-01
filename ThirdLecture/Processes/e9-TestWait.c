#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h> /* For wait */
#include <sys/wait.h>  /* For wait */


int
main (int argc, char ** argv) {
  int rv;

  if (fork()) {
    // F waits a child
    printf ("\nParent (%d) 1\n", getpid()); fflush (stdout);
    wait (&rv);
    // Waits other childs that do not exist, as a consequence
    // waits are not blocking, and F proceeds after passing the first wait
    printf ("\nParent (%d) 2\n", getpid()); fflush (stdout);
    wait (&rv);
    printf ("\nParent (%d) 3\n", getpid()); fflush (stdout);
    wait (&rv);
    printf ("\nParent (%d) 4\n", getpid()); fflush (stdout);
    wait (&rv);
    printf ("\nParent (%d) 5\n", getpid()); fflush (stdout);
  } else {
    if (fork ()) {
      // Child that is waited by the parent
      printf ("  S (%d) 1\n", getpid()); fflush (stdout);
      // If sleep is executed
      // SS does exit and becomes a zombie
      // F continues to wait
      // until S does the wait and unblocks the other processes
      //sleep (20);
      // In fact, if S is blocked, F waits and SS is a zombie forever
      // Then, if a kill is executed on S (from shell), the other three processes terminate
      pause ();
      wait (&rv);
      printf ("  S (%d) 2\n", getpid()); fflush (stdout);
      exit (0);
    } else {
      // Child of the child that sleeps and exits
      printf ("    SS (%d) 1\n", getpid()); fflush (stdout);
      sleep (5);
      printf ("    SS (%d) 2\n", getpid()); fflush (stdout);
      exit (0);
    }
  }

}