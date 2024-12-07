#!/bin/bash

if [ ! $# -eq 2 ]
then
    echo "Invalid number of arguments specified"
    exit 1
fi

if [ ! -d $1 ];
then
    echo "Directory does not exist"
    exit 1
fi

number_of_matches=$(grep -orI $2 $1 | wc -l)
number_of_files=$(grep -crl $2 $1 | wc -l)

echo "The number of files are $number_of_files and the number of matching lines are $number_of_matches"

