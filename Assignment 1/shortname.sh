#!/bin/bash
#NATHAN SARIC - 09/25/2020

#Script 3: shortname.sh
#This script takes the name of a directory as a parameter and
#deletes all files whose names contain less than four characters.

directory=$1

cd $directory
rm ? ?? ???
