import os

#if you call fork, except pid everything will be dublicated

def main():
    #1
    pid1 = os.fork()
    #2
    pid2 = os.fork()
    #4
    if pid1 == 0:
        print("I am child")
    else:
        print("I am parent")

if __name__ == "__main__":
    main()


