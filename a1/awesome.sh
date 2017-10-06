#!/bin/bash
#$1 $2 ...$NF
dir=$1
k=$2



intCheck="$k |grep '/[0-9]+'"

if [ -z "$dir" ] || [ -z "$k" ];then
  echo "Please enter both a valid directory and a maximum file size respectively."
  echo "Or type awesome.sh --help for help."
  exit
fi



if [ ! -d "$dir" ];
  then
    echo "No such directory"
    echo "Please enter both a valid directory and a maximum file size respectively."
    exit
fi

if [ $k == "--help" ]
  then
    echo "awesome.sh takes argument k, and return all directories that are larger than k bytes."
    exit
fi

names=`ls -l $dir|awk -v k="$k" '$5 > k {print $NF}'|grep '[.]'`
if [[ $names == "" ]]
then
  echo "No file/folder that are larger than $k bytes."
fi
echo "${names[*]}"
