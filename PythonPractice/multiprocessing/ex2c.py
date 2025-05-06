# Starting from the given program, modify it so that the parent waits for all its children to terminate, using the os.waitpid(pid, 0) function
# Note: you may need to modify different parts of the program

import os
import time

# Variable that keeps the list of children created
pidlist = []


for i in range(4):
  processid = os.fork()

  if processid > 0:
    print(f"Parent with child:", processid)
    pidlist.append(processid)
  else :
    print(f"Child:", os.getpid())
    time.sleep(1)
    exit(0)

#time.sleep(100)

for pid in pidlist:
   pid, status = os.waitpid(pid, 0)
   print(f"Parent: Child with pid {pid} have terminated with status {status}")

print("Parent: All children have terminated!")