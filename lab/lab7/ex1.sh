#!/bin/bash

echo "Enter a directory name:"
read n1
echo "Enter a function name:"
read n2
echo "Enter a output file name:"
read n3


grep -Hnr "$n2 *(.*)" $r1 | sort -t ':' -k 1,1 -k 2,2rn > $n3
