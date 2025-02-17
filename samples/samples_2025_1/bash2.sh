#!/bin/bash

if [ $# -ne 1 ]
then
    echo "usage <filename>"
    exit 1
fi

while read line
do
    echo $line | wc -w
done < $1