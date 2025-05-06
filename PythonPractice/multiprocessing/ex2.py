import os
import time

processid = os.fork()
print("ProcessID:", processid)

processid = os.fork()
print("ProcessID:", processid)

time.sleep(100)