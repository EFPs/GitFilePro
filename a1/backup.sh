#!/bin/bash

file=$1



time="_"`date -u +%F_%T`
fileName=`basename $file`

#echo `mkdir -p /subm/u5881050/backups`

echo `mkdir -p /subm/u5881050/backups/$fileName$time`
num=`cat $file|grep '.'`
if [[ num=="" ]]
then
  echo `cp -r $file/* /subm/u5881050/backups/$fileName$time`
else
  echo `cp -r $file /subm/u5881050/backups/$fileName$time`


#echo "$B"
echo "Backup $file completed successfully."
