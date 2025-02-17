#!/bin/bash

while read -n 1 i 
do 
    echo $i 
done < $1