#!/bin/bash
writefile=$1
writestr=$2
echo "writefile=${writefile}, writestr=${writestr}"
if [ $# -eq 2 ]
then
	echo "2 Valid Args provided as expected"
	dir="${writefile%/*}"
	if [ -d ${dir} ]
	then
		echo "${dir} exists"
		if [ -f $writefile ]
		then
			echo "${writefile} exists! "
		else
			touch ${writefile}
			if [ $? -ne 0 ]
			then 
				echo "Error: Failed to create new file"
				exit 1	
			fi
			echo "Created New File ${writefile} "
		fi
	else
		echo "${dir} DOES NOT EXIST"
		mkdir -p ${dir}
		if [ $? -ne 0 ]
		then
			echo "Error: Failed to create new directory"
			exit 1
		fi
		echo "New Directory created at ${dir} "
		touch ${writefile}
		if [ $? -ne 0 ]
		then
			echo "Error: Failed to create new file"
		fi
		echo "Created New File in New Directory ${writefile} "	
	fi
	echo "${writestr}" > ${writefile} 
	echo "Populated file with content: ${writestr}"
	exit 0
else
	echo "Error: Invalid Args, Please provide 2 Args from the cmd line! "
	exit 1
fi

