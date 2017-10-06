#!/bin/bash

file=$1

if [ -z "$file" ];then
  echo "Please enter a directory of a folder with out / at the end."
  exit
fi

if [ ! -d "$file/" ];
  then
    echo "No such directory"
    echo "Please enter a valid directory."
    exit
fi

time="_"`date -u +%F_%T`
fileName=`basename $file`

#echo `mkdir -p /subm/u5881050/backups`

echo `mkdir -p /subm/u5881050/backups/$fileName$time`
echo `cp -R $file/ /subm/u5881050/backups/$fileName$time`

echo "Backup $file completed successfully."


#echo "$B"
