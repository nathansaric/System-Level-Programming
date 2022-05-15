#!/bin/bash
#NATHAN SARIC -  09/25/2020

#Script 4: fixWeird.sh
#This script takes the name of a directory as a parameter and
#removes the owner's write permission from every weird file inside that directory.
#A weird file is a file whose name begins and ends with a lower-case vowel.

directory=$1

cd $directory
chmod u-w [aeiou]*[aeiou]
