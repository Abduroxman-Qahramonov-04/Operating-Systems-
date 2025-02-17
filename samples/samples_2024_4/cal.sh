#!/bin/bash

if [ $# -ne 1 ]
then
    echo "usage <filename>"
    exit 1
fi

firstDay=""
lastDay=""
array=()
let count=0

weeks=$(head -n 2 $1 | tail -n 1)
firstLine=$(head -n 3 $1 | tail -n 1)
lastLine=$(tail -n 1 $1)



for i in $firstLine
do
    ((count++))
    if [[ "$i" != " " ]]
    then 
        firstDay=$i
        break
    fi
done

echo $count
echo "First day $(echo $weeks | cut -d " " -f $count)"

count=1
for i in $lastLine
do
    
    if [[ "$i" != " " ]]
    then 
        lastDay=$i
    fi
    ((count++))
done
echo $((--count))
echo "Last day $(echo $weeks | cut -d " " -f $((count))"