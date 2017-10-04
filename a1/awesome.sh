#!/bin/bash
#$1 $2 ...$NF
k=$1
intCheck="$k |grep '/[0-9]+'"

if [[ $k =~ ^-?[0-9]+$ ]]
then
  names=`ls -la|awk -v k="$k" '$5 > k {print $NF}'`
  if [[ $names == "" ]]
  then
    echo "No file/folder that are larger than $k bytes."
  fi
  echo "${names[*]}"
else
  if [ $k == "--help" ]
  then
    echo "awesome.sh takes argument k, and return all directories that are larger than k bytes."
  else
    echo "Wrong Argument"
    echo "type awesome.sh --help for help."
  fi
fi
