#!/bin/bash

filesdir=$1
searchstr=$2
echo "filesdir: ${filesdir}, searchstr: ${searchstr}"
if [ $# -eq 2 ] 
then 
	echo "2 Args provided as expected! "
	if [ ! -d ${filesdir} ]
	then
		echo "Error: Directory ${filesdir} does not exist! "
		exit 1
	else
		filecount=$(find ${filesdir} -type f | wc -l)
		linecount=$(grep -o -r ${searchstr} ${filesdir} | wc -l)
		echo "The number of files are ${filecount} and the number of matching lines are ${linecount}" 
	fi
	exit 0
else
	echo "Error: Invalid Args, Please provide 2 args from the cmd line! "
	exit 1
fi

