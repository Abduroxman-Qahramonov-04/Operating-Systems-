#!/bin/bash

if [ $# -ne 1 ]
then 
    echo "Usage $0 file"
    exit 1
fi

path=`find ~ -type d -name $1`
echo $path
cd "$path"
cd ..
for i in `ls $1`
do 
    mv $path/$i $path/$(echo $i | tr A-Z a-z)
done
exit 0
