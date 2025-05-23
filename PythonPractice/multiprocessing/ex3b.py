import os
import time

a = 0
b = 0

a = os.fork()  # First fork
time.sleep(0.1)  # Small delay to order prints
print(f"[After fork 1] PID: {os.getpid()}, PPID: {os.getppid()}, a = {a}")

if a == 0:
    b = os.fork()  # Second fork (only in child of first fork)
    time.sleep(0.1)
    print(f"[After fork 2] PID: {os.getpid()}, PPID: {os.getppid()}, b = {b}")

os.fork()  # Third fork (in all current processes)
time.sleep(0.1)
print(f"[After fork 3] PID: {os.getpid()}, PPID: {os.getppid()}")

if (a != 0) and (b == 0):
    os.fork()  # Fourth fork (conditional)
    time.sleep(0.1)
    print(f"[After fork 4] PID: {os.getpid()}, PPID: {os.getppid()}")


time.sleep(100)
