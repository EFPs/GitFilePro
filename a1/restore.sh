#!/bin/bash

fileName=$1

#Check if recovered already exist.
if [ ! -d "./recovered" ];
then
  echo `mkdir ./recovered`
fi

#Check if such folder already exist.
if [ ! -d "./recovered/$fileName" ];
then
  echo `mkdir ./recovered/$fileName`

else
  echo `find ./recovered/$fileNames -type f -delete`
  #echo `rm -rf ./recovered/$fileNames`
fi
#get the list of file , sort it in order low to hi, get the last one(mose resent one)
RecentFile=`ls /subm/u5881050/backups/ |cat|grep \^$fileName |cat| sort -n | tail -n1| cat`


if [[ -z $RecentFile ]]; then
  echo "No such file in backups."
  exit
fi


#copy all the content inside the latest folder
echo `cp -r /subm/u5881050/backups/$RecentFile/* ./recovered/$fileName`


#print
echo "$fileName has been restored to ./recovered/$fileName"
