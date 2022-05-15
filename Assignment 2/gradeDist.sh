#!/bin/bash
#NATHAN SARIC - 10/09/2020

#Script 1: gradeDist.sh
#This script takes two parameters and prints the distribution of grades (A,B,C,D or F)
#for several submission files.
#The two parameters include: the name of the marking script and the name of the
#folder containing the folder containing the assignment submission files

fileName=$1
folderName=$2

#ERROR HANDLING:
#If the script is called with a number of arguments other than two [EXIT 1]
if [[ "$#" != "2" ]];
then
	echo "error: gradeDist.sh needs two arguments" >&2
	exit 1

#ERROR HANDLING:
#If the first argument is not the name of an existing, executable file [EXIT 2]
elif [[ ! -x $fileName ]];
then
	echo "error: $fileName is not an existing, executable file" >&2
	exit 2

#ERROR HANDLING:
#If the second argument is not the name of an existing directory [EXIT 3]
elif  [[ ! -d $folderName ]];
then
	echo "error: $folderName does not exist or is not a directory" >&2
	exit 3
fi

#Setting the count for each letter grade to 0
count[ABCDF]=0

#Creating a temporary file to store all grades outputted from the marking script
touch allGrades

#Looping through each file in the supplied folder and redirecting the output from
#the marking script to the temporary 'allGrades' file
for file in $folderName/*;
do
	$fileName $file >> allGrades
done

#Looping through each letter grade in the temporary 'allGrades' file and
#incrementing the appropriate grade counter by 1
for grade in `cat ./allGrades`;
do
	if [[ "$grade" == "A" ]];
	then (( countA++ ))

	elif [[ "$grade" == "B" ]];
        then (( countB++ ))

	elif [[ "$grade" == "C" ]];
        then (( countC++ ))

	elif [[ "$grade" == "D" ]];
        then (( countD++ ))

	else (( countF++ ))
	fi
done

#Creating an array of letter grade and the appropriate count for easier display to the terminal
gradesArray=("A: $countA" "B: $countB"  "C: $countC"  "D: $countD"  "F: $countF" )

#Displaying the letter grade and the appropriate count in the correct format to the terminal
for val in "${gradesArray[@]}";
do
	echo $val
done

#Removing the temporary file, so that the grades do not accumulate and return incorrect counts
#the next time the script is run
rm allGrades
