import threading
import time

c1 = 0
c2 = 0
c3 = 0
c4 = 0
ct = 0

def task1():
    global c1
    while True:
        c1+=1
        time.sleep(0.1)
def task2():
    global c2
    while True:
        c2+=1
        time.sleep(0.1)
        
def task3():
    global c3
    while True:
        c3+=1
        time.sleep(0.1)
def task4():
    global c4
    while True:
        c4+=1
        time.sleep(0.1)
def task5(names):
    global c1
    global c2
    global c3
    global c4
    global ct
    while True:
        ct = c1+c2+c3+c4
        print(f"{threading.current_thread().name} -  total count:{ct}")
        print(f"{names[0]} -  c1 count:{c1}")
        print(f"{names[1]} -  c2 count:{c2}")
        print(f"{names[2]} -  c3 count:{c3}")
        print(f"{names[3]} -  c4 count:{c4}")
        time.sleep(1)

def main():
    th1 = threading.Thread(target=task1,name="th1")
    th2 = threading.Thread(target=task2,name="th2")
    th3 = threading.Thread(target=task3,name="th3")
    th4 = threading.Thread(target=task4,name="th4")
    names = []
    names.extend([th1.name,th2.name,th3.name,th4.name])
    th5 = threading.Thread(target=task5,name="th5", args=(names,))

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