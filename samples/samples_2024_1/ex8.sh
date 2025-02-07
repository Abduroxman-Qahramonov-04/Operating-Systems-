

if [ $# -lt 1 ]
then
    echo "usage <list of files>"
    exit 1
fi

for file in "$@"
do
    ls -l $file > /dev/null 
    if [ $? -eq 0 ]
    then
        tempR=""
        tempW=""
        if [ -f $file ]
        then
            if [ -r $file ]
            then 
                tempR="YES"
            else
                tempR="NO"
            fi
            if [ -w $file ]
            then 
                tempW="YES"
            else
                tempW="NO"
            fi
            fileSize=$(ls -l $file | cut -d ' ' -f 5)
            echo "$file $fileSize read-perm $tempR, write-perm $tempW"
            
        elif [ -L "$file" ]
        then 
            echo "Hello"
            echo $(ls -l $file | cut -d ' ' -f 4,11)
        fi
    else
        echo "file $file does not exist" 
    fi
done
