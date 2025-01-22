#!/bin/bash

echo "Enter a file name:"
read n1

for i in `cat $n1`
do
    echo $i | wc -c >> temp.txt
done
echo `sort -rn temp.txt | head -n 1`
echo `wc -l $n1`

rm temp.txt
exit 0