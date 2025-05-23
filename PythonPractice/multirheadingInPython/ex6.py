import time
import threading

NUMBER_OF_THREADS=10
ITERATIONS=1000000000
PER_THREAD=ITERATIONS//NUMBER_OF_THREADS

i = 0

def worker():
    global i
    for j in range(PER_THREAD):
        i+=1

def main():
    threads = []
    start = time.time()
    for i in range(NUMBER_OF_THREADS):
        t = threading.Thread(target=worker)
        threads.append(t)
        t.start()
    for t in threads:
        t.join()
    end = time.time()
    print(f"{end-start} seconds")


if __name__ == "__main__":
    main()