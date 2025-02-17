#!/bin/bash

if [ $# -ne 1 ]
then
    echo "usage <path>"
    exit 1
fi

cd $1

let iterator1=0
let iterator2=0

for file in $( find . -type f -size -1M -name "*.txt" )
do
    let iterator1=iterator1+1
    cat $file >> "small_files_${iterator1}.txt"
done

for file in $( find . -type f -size +1G -name "*.txt" )
do
    let iterator2=iterator2+1
    cat $file >> "small_files_${iterator2}.txt"
done