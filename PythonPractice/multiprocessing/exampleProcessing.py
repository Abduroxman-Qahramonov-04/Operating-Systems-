import os

def main():
    pid1 = os.fork()
    pid2 = os.fork()

    print("Hello")

if __name__ == "__main__":
    main()


