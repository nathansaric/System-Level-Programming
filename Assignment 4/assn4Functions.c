/* NATHAN SARIC - 11/20/2020
 *
 * Script 1: assn4Functions.c
 * This program contains three functions that are used in assn4 to assist in separating a sentence
 * into multiple words. Every word and every array of words is allocated on the heap and the heap
 * is cleaned after processing each sentence.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// Returns the number of space characters (' ') in its parameter
int countSpaces(char theString[]) {
  int i = 0;
  int numSpaces = 0;

  while (theString[i] != '\0') {
    if (theString[i] == ' ')
      numSpaces++;

    i++;
  }

  return numSpaces;
}

/*
 * Splits a string into individual words.
 * First parameter: a string. Assumes that the words in the string are separated by
 * single spaces, with no spaces before the first word or after the second word. So
 * the number of words is equal to the number of spaces plus 1. Punctuation will always
 * appear at the end of a word and should be considered part of the word.
 * Second parameter: the address of an integer in which the function will store the
 * number of words in the string.
 * Return value: pointer to the beginning of an array of strings containing the individual
 * words from the sentence. This function creates that array and the strings inside the array,
 * using space from the heap for both the array and the individual words. The strings are copies
 * of words from the sentence, not pointers into the sentence.
 */
char** splitString(char theString[], int *arraySize) {
  char** stringPointer = malloc(strlen(theString) * sizeof(char*)); //allocating space on the heap for the array

  if (stringPointer == NULL)
    exit(1);

  int numWords = 0;
  int numLetters = 0;
  int i = 0;
  int j;

  while (i < strlen(theString)) {
    while ((theString[numLetters + i] != ' ') && (theString[numLetters + i] != '\n')) {
	     numLetters++;
    }

    stringPointer[numWords] = malloc((numLetters + 1) * sizeof(char)); //allocating space on the heap for each word

    for (j = 0; j < numLetters; j++) {
      stringPointer[numWords][j] = theString[i + j];

      if (j == (numLetters - 1))
        stringPointer[numWords][j + 1] = '\0';
    }

    numWords++;
    i += (numLetters + 1);
    numLetters = 0;
  }

  *arraySize = numWords;
  return stringPointer;
}

/* Cleans up the space used by an array of words.
 * Parameters: array of words and its length
 * Assumes that the array of words and each individual word are stored on the heap.
 * Frees the space used by the array AND each individual word. Assumes that all
 * words are null-terminated strings.
 */
void cleanup(char *words[], int numWords) {
  int i;

  for (i = 0; i < numWords; i++) {
    free(words[i]); // frees the space used by each word
  }

  free(words); // frees the space used by the array
}
