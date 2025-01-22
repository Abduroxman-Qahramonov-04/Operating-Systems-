#!/bin/bash

if [ $# -ne 1 ]
then 
    echo "Wrong command line argument"
    exit 1
fi

words=()
occurences=()

for i in `cat $1`
do
    found=false
    for index in "${!words[@]}"
    do 
        if [[ "${words[index]}" == $i ]]
        then 
            occurences[index]=$((occurences[index] + 1))
            found=true
            break
        fi
    done
    if [[ $found == false ]]
    then 
        words+=("$i")
        occurences+=(1)
    fi
done

for index in "${!words[@]}"
do
    echo "${words[$index]} ${occurences[$index]}"
done