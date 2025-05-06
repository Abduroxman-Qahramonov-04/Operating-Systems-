import os


def main():
    n = int(input("Enter number of process:"))
    parent_id = os.getpid();
    for i in range(n):
        id = os.fork()

        if id != 0:
            #parent shoudl create a new child so it has to pass
            pass
        elif id == 0:
            #child should be stopped 
            
            print(f"Child {i+1} with PID {str(os.getpid())} has the parent with id {parent_id}")
            break

if __name__ == "__main__":
    main()