import threading
import os

sem1 = threading.Semaphore(1)
sem2 = threading.Semaphore(0)
sem3 = threading.Semaphore(0)

def task1():
    sem1.acquire()
    print("Thread 1")
    sem3.release()
def task2():
    sem2.acquire()
    print("Thread 2")
    sem1.release()
def task3():
    sem3.acquire()
    print("Thread 3")
    sem2.release()

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