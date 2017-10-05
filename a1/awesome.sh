#!/bin/bash
#$1 $2 ...$NF
dir=$1
k=$2



intCheck="$k |grep '/[0-9]+'"

# if [ "$2"=="" ];
# then
#   echo "Wrong Argument"
#   echo "type awesome.sh --help for help."
#
#   exit
# fi

if [[ ! -d "$dir"]]
  then
    echo "No such directory"
    exit
fi

if [[ "$k" =~ ^-?[0-9]+$ ]]
then
  names=`ls -l $dir|awk -v k="$k" '$5 > k {print $NF}'|grep '[.]{1}'`
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
