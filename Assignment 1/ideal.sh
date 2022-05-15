#!/bin/bash
#NATHAN SARIC - 09/25/2020

#Script 1: ideal.sh
#This script takes the name of a directory as a parameter and
#lists the names of all ideal files in the directory.
#An ideal file is a file whose name contains at least two lower-case i's.

directory=$1

cd $directory
echo *i*i*.*
