import os
import time

def main():
    id = os.fork()
    if id == 0:
        time.sleep(3)
        print("CHild has finished")
    else:
        #os.waitpid(id,0)
        print("Parent has finished")
        
if __name__ == "__main__":
    main()