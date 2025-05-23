import time
import threading

def main():
    i = 0
    start = time.time()
    for j in range(1000000000):
        i+=1
    end = time.time()
    print(f"{end-start} seconds")
if __name__ == "__main__":
    main()