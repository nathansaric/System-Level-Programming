#!/bin/bash
#NATHAN SARIC - 10/09/2020

#Script 2: pigLatin.sh
#This script takes a string of lowercase letters and prints the Pig Latin equivalent
#of the supplied parameter.

translate=$1
ay="ay"
way="way"

#ERROR HANDLING:
#If script is called with a number of arguments other than one [EXIT 1]
if [[ "$#" != "1" ]];
then
        echo "error: wrong number of arguments for pigLatin.sh (needs exactly one)" >&2
        exit 1
fi

#Converting the supplied string of letters to an array where each index
#corresponds to a letter, for easier manipulation
for i in $(seq 0 ${#translate});
do
	translateArray[$i]=${translate:$i:1};
done

firstLetter=${translateArray[0]}

#PIG LATIN CONDITION:
#If word starts with vowel (a,e,i,o or u), add "way" to the end of the word
if [[ "$firstLetter" == [aeiou] ]];
then
        pigLatin="$translate$way"
        echo "$pigLatin"

#PIG LATIN CONDITION:
#If word starts with consonants, move the consonant cluster before
#the first vowel to the end of the word and then add "ay" at the end
elif [[ "$firstLetter" != [aeiou] ]];
then
        while [[ "${translateArray[0]}" != [aeiou] ]];
        do
                translateArray=(${translateArray[*]:1} "${translateArray[0]}")
        done

        translateArray+=($ay)
        pigLatin=$(IFS=; echo "${translateArray[*]}")
        echo "$pigLatin"
fi
