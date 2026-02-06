#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *insert_element(Node *root, int value) {

  if (!root)
    return new Node{value, nullptr, nullptr};

  if (value > root->data)
    root->right = insert_element(root->right, value);
  else
    root->left = insert_element(root->left, value);

  return root;
}

// File to binary tree
Node *create_tree_from_file(std::ifstream &inputfile) {

  // Declare read-container
  int value;

  Node *tree = nullptr;

  while (inputfile >> value) {
    tree = insert_element(tree, value);
    std::cout << value << std::endl;
  }

  return tree;
}

void print_tree(Node *tree) {
  if (tree == nullptr)
    return;

  print_tree(tree->left);
  std::cout << tree->data << std::endl;
  print_tree(tree->right);
}

int main(int argc, char *argv[]) {

  std::string inputfilename = argv[1];
  std::ifstream arrayfile(inputfilename);

  Node *tree = create_tree_from_file(arrayfile);

  std::cout << "Current tree state: " << std::endl;
  print_tree(tree);

  return 0;
}
