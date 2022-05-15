/* NATHAN SARIC - 12/04/2020
 *
 * Script 1: BST.c
 * This program contains five functions that are used in testBST. The functions assist in
 * printing a tree, searching for a value in a tree, adding a value to a tree, and summing
 * all values in a tree.
 */

#include <stdio.h>
#include <malloc.h>
#include "BST.h"

#define INDENT_INCREASE 4

// Prints a tree or sub-tree, indented. The second parameter is
// the number of spaces to indent the root. This is a helper
// function for printTree.
void printTreeWithIndent(BST tree, int indentLevel) {
  if (tree != NULL) {
    int i;
    printTreeWithIndent(tree->right, indentLevel+1);
    for (i = 0; i < indentLevel*INDENT_INCREASE; i++)
      printf(" ");
    printf("%d\n", tree->value);
    printTreeWithIndent(tree->left, indentLevel+1);
  }
}

/* Displays an indented representation of a BST.
 * The tree is displayed as if were rotated 90 degrees counter-clockwise.
 * In other words, the root is on the left, the right subtree is
 * above the root and the left subtee is below the root.
 */
void printTree(BST tree) {
  printTreeWithIndent(tree, 0);
}

// Searches for a value in a binary search tree.
// If the value occurs in the tree, returns 1, otherwise returns 0.
int search(BST tree, int target) {
  if (tree == NULL)
    return 0;

  if (target == tree->value)
    return 1;
  else if (target < tree->value)
    return search(tree->left, target);
  else if (target > tree->value)
    return search(tree->right, target);
}

/* Adds a new value to a tree. Returns a pointer to
 * the root of the modified tree. This should be the
 * same as the root of the original tree unless the
 * original tree was empty (NULL).
 * Does not add duplicate values to a tree; if the
 * value is already in the tree there is no error
 * message but the tree is not changed.
 */
BST add(BST tree, int newValue) {
  if (tree == NULL) {
    tree = malloc(sizeof(struct node));
    tree->left = NULL;
    tree->right = NULL;
    tree->value = newValue;
  }

  else if (newValue < tree->value)
    tree->left = add(tree->left, newValue);
  else if (newValue > tree->value)
    tree->right = add(tree->right, newValue);

  return tree;
}

// Returns the total of all of the values in the tree.
// The total of the values in an empty tree is 0.
int total(BST tree) {
  if (tree == NULL)
    return 0;
  else
    return (tree->value + total(tree->left) + total(tree->right));
}
