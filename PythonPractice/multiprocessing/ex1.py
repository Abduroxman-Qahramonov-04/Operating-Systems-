import os

def main():
    id1 = os.fork()

    if id1 != 0:
        print("Hello from PARENT:"+ str(os.getpid()))
        #parent
        id2 = os.fork()
        if id2 != 0:
            id3 = os.fork()
            if id3 == 0:
                print("Hello from child 3:"+ str(os.getpid()))
        else:
            print("Hello from child 2:"+ str(os.getpid()))

    else:
        print("Hello from child 1:"+ str(os.getpid()))


if __name__ == "__main__":
    main()