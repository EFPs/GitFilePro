#!/bin/bash
#$1 $2 ...$NF
k=$1
if [$k -eq $k 2>/del/null ]
then
  names=`ls -la|awk -v k="$k" '$5 > k {print $NF}'`
  echo "${names[*]}"
else
  echo "Wrong Argument"
  echo "type --help for help."
fi
