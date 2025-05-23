import os
import random
import sympy

NUMBERS = 10000
THREADS = 4
numbers = []

def child_main(i) :
  for j in range( int(NUMBERS / THREADS)) :
    num = j * THREADS + i
    if sympy.isprime(numbers[num]) :
      print(f"Process {i}, {num}: Number {numbers[num]} is prime")
    else :
      print(f"Process {i}, {num}: Number {numbers[num]} is not prime")

def main() :
  # Generate a list of random numbers between 1 and 1000
  for i in range(NUMBERS) :
    numbers.append( random.randint(1, 1000) )

  for i in range(THREADS) :
    processid = os.fork()

    if processid > 0 :
      print(f"Parent with child:", processid)
    else :
        print(f"Child with parent:", os.getpid(), os.getppid())
        child_main(i)
        exit(0)

if __name__=="__main__":
  main()
