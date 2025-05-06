import os
import time

processid = os.fork()
print("ProcessID:", processid)

if processid == 0 :
   exit(0)

time.sleep(100)

os.waitpid(processid, 0)

# Add your code here