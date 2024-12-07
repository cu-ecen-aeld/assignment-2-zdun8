#!/bin/bash

if [ ! $# -eq 2 ];
then 
    echo "Invalid number of arguments specified"
    exit 1
fi

created=0

if [ ! -d $1 ];
then
   mkdir -p $(dirname $1) 
fi

echo $2 > $1