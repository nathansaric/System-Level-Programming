#!/bin/bash
#NATHAN SARIC - 09/25/2020

#Script 2: status.sh
#This script takes four parameters and prints out a three
#line message using those parameters.
#The four parameters include: a first name, a last name, an emotion, and a number

firstName=$1
lastName=$2
emotion=$3
number=$4

echo "My name is $firstName $lastName."
echo "I have $number hours of homework."
echo "I am feeling $emotion."
