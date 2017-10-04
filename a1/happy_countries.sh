#!/bin/bash
countries=`curl -s https://en.wikipedia.org/wiki/World_Happiness_Report?action=raw | grep -E '\|{2}\{{2}....\|[a-z,A-Z ()]+' | cat|sed 's/NA/data-sort-value="2"|{{Increase}} 2/g'|cat| cut -d'|' -f8 | cat| cut -d'}' -f1  | cat`
echo "${countries[*]}"
#printf "$countries\n"
