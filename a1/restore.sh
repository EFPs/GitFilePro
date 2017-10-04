#!/bin/bash

fileName=$1


echo `rm -rf ./recovered/$fileName`


#get the list of file , sort it in order low to hi, get the last one(mose resent one)
RecentFile=`ls /subm/u5881050/backups/ |cat|grep \^$fileName |cat| sort -n | tail -n1| cat`
#echo "hi"
#echo `$RecentFile`
#echo "hi"
echo `mkdir ./recovered/$fileName`
echo `cp -r /subm/u5881050/backups/$RecentFile/* ./recovered/$fileName`

#print
echo "$fileName has been restored to ./recovered/$fileName"
