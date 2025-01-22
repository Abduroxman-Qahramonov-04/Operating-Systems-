#include <stdio.h>
#include <stdlib.h>

typedef struct my_mutex{
    int ticketNumber;  // Keeps track of the next available ticket
    int turnNumber;    // Represents the turn being serviced

}my_mutex_t;

int atomicIncrement (int *var) {
  int tmp = *var;
  *var = tmp + 1;
  return (tmp);
}

void my_lock(my_mutex_t mutex){
    int myTurn = atomicIncrement(&mutex.ticketNumber);
    while(myTurn != mutex.turnNumber);
}
void my_unlock(my_mutex_t mutex){
    atomicIncrement(&mutex.turnNumber);
}

void my_init(my_mutex_t mutex){
    mutex.ticketNumber = 0;
    mutex.turnNumber = 0;
}

int main(){
    return 0;
}