import threading
import os
import time

sem1 = threading.Semaphore(2)
sem2 = threading.Semaphore(0)
sem3 = threading.Semaphore(0)

def task1():
    while True:
        sem1.acquire()
        sem1.acquire()
        print("Thread 1")
        time.sleep(1)
        sem2.release()
        sem3.release()
def task2():
    while True:
        sem2.acquire()
        print("Thread 2")
        time.sleep(1)
        sem1.release()
def task3():
    while True:
        sem3.acquire()
        print("Thread 3")
        time.sleep(1)
        sem1.release()

def main():

    

    th1 = threading.Thread(target=task1)
    th2 = threading.Thread(target=task2)
    th3 = threading.Thread(target=task3)

    th1.start()
    th2.start()
    th3.start()

    th1.join()
    th2.join()
    th3.join()

if __name__ == "__main__":
    main()