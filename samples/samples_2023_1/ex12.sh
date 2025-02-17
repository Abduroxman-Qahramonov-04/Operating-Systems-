#!/bin/bash

if [ $# -ne 1 ]
then 
    echo "usage $0 <username>"
    exit 1
fi

line=$(cat "/etc/passwd" | egrep -e "^$1:")
if [ $? -eq 1 ]
then 
    echo "There is no such a user"
    exit 1
fi

HOME_FOLDER=$(echo $line | cut -d ":" -f 6)

rm -r $HOME_FOLDER

cat "/etc/passwd" | egrep -ve "^$line:" > /etc/passwd 

echo "$line"
echo "$HOME_FOLDER"