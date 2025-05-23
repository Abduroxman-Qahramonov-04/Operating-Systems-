import threading
import os
import time


sem2 = threading.Semaphore(0)
sem3 = threading.Semaphore(0)
sem4 = threading.Semaphore(0)
sem5 = threading.Semaphore(0)



def task1():
    print("Thread 1")
    time.sleep(1)
    sem2.release()
    sem3.release()
    
def task2():
    sem2.acquire()
    print("Thread 2")
    time.sleep(1)
    sem4.release()
    
def task3():
    sem3.acquire()
    print("Thread 3")
    time.sleep(1)
    sem4.release()
    sem5.release()

def task4():
    sem4.acquire()
    sem4.acquire()
    print("Thread 4")
    time.sleep(1)
    sem5.release()

def task5():
    sem5.acquire()
    #if 4 and 5 should be in parralell we don't need second acquire().
    print("Thread 5")
    time.sleep(1)

def main():

    th1 = threading.Thread(target=task1)
    th2 = threading.Thread(target=task2)
    th3 = threading.Thread(target=task3)
    th4 = threading.Thread(target=task4)
    th5 = threading.Thread(target=task5)

    th1.start()
    th2.start()
    th3.start()
    th4.start()
    th5.start()

    th1.join()
    th2.join()
    th3.join()
    th4.join()
    th5.join()

if __name__ == "__main__":
    main()