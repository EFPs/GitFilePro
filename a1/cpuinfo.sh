#!/bin/bash

Spec=`cat /proc/cpuinfo | grep "model name"| cat | cut -d':' -f 2|cat | sed 's/ //'`
echo "${Spec[*]}"
