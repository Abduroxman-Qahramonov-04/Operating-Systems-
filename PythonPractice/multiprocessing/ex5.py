import os
import time


def main():
    for i in range(4):
        id = os.fork()
        if id != 0:
            pass
        else:
            time.sleep(1)
            print("Hello")
            exit(0)
if __name__ == "__main__":
    main()