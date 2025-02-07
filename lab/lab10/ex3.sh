#!/bin/bash

if [ $# -ne 2 ]
then
    echo "Usage: user dir"
    exit 1
fi

for file in $(find $2 -user $1 -type f)
do 
    grep -e "^\*\*\*Da Modificare" $file
    if [ $? -eq 0 ]
    then 
        grep -v '^\*\*\*Da Modficare' $file > /tmp/tmp$$.txt
        mv /tmp/tmp$$.txt $file"_mod"
        rm -f $file
    fi
done
exit 0

