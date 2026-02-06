#include "BSTFUNCTIONS.h"
#include <cstdlib>
#include <iostream>

int *createarray(int size) {
  int *array = new int[size];

  for (int i = 0; i < size; i++)
    array[i] = std::rand() % (10 + 1);

  return array;
}

void printarray(int *array, int size) {

  std::string out = "[";
  for (int i = 0; i < size; i++) {
    out += std::to_string(array[i]);
    if (i != size - 1)
      out += " ";
  }
  out += "]";
  std::cout << out << std::endl;
  std::cout << "\n" << std::endl;
}

node *insert_element(node *tree, int value) {

  if (!tree)
    return new node{value, nullptr, nullptr};

  if (value > tree->data)
    tree->right = insert_element(tree->right, value);
  else
    tree->left = insert_element(tree->left, value);

  return tree;
}

node *createBST(int *array, int size) {
  if (size == 0)
    return nullptr;

  node *tree = new node{array[0], nullptr, nullptr};

  for (int i = 1; i < size; i++) {
    tree = insert_element(tree, array[i]);
  }

  return tree;
}

void fancyprintBST(node *tree, int depth = 0) {
  if (!tree)
    return;
  fancyprintBST(tree->right, depth + 1);
  for (int i = 0; i < depth; i++) {
    std::cout << "   ";
  }
  std::cout << tree->data << std::endl;
  fancyprintBST(tree->left, depth + 1);
}
