#include <cstdlib>
#include <fstream>
#include <iostream>

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

Node *from_file_to_tree(std::ifstream &inputfile) {

  int value;
  Node *tree = nullptr;

  while (inputfile >> value)
    tree = insert_element(tree, value);

  return tree;
}

void print_tree(Node *root) {
  if (root == nullptr)
    return;
  print_tree(root->left);
  std::cout << root->data << std::endl;
  print_tree(root->right);
}

int main(int argc, char *argv[]) {

  std::ifstream input(argv[1]);

  Node *tree = from_file_to_tree(input);

  print_tree(tree);
}
