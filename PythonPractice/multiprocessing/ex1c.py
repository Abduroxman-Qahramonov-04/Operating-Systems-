import os
import time

def main():
    n = int(input("Enter number of process:"))
    parent_id = os.getpid();
    temp_id = -1
    for i in range(n):
        id = os.fork()

        if id != 0:
            #parent shoudl create a new child so it has to pass
            pass
        elif id == 0:
            if i == 0:
                os.fork()
            #child should be stopped 
            
            print(f"Child {i+1} with PID {str(os.getpid())} has the parent with id {str(os.getppid())}")
            break

if __name__ == "__main__":
    main()