#include <cstdlib>
#include <iostream>
#include <string>

// Make a function that makes a binary tree of an array with random integers but
// predetermined size

struct Node {
  int data;
  Node *right;
  Node *left;
};

int *create_array(int size) {
  std::string output = "[";
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = std::rand() % 11;
    output += std::to_string(array[i]);
    output += " ";
  }
  output += "]";
  std::cout << output << std::endl;
  return array;
}

Node *insert_node(Node *tree, int value) {

  // If no tree, create a root
  if (!tree)
    return new Node{value, nullptr, nullptr};

  if (value > tree->data) {
    std::cout << "Inserting right" << std::endl;
    tree->right = insert_node(tree->right, value);
  } else {
    std::cout << "Inserting left" << std::endl;
    tree->left = insert_node(tree->left, value);
  }

  return tree;
}

Node *create_tree(Node *root, int *array, int size) {
  std::cout << "Building tree" << std::endl;

  // For each element in the array, insert a node in the tree.
  for (int i = 0; i < size; i++) {
    std::cout << "started iterations" << std::endl;
    root = insert_node(root, array[i]);
  }
  return root;
}

void print_tree(Node *root) {

  if (root == nullptr)
    return;

  print_tree(root->left);
  std::cout << root->data << std::endl;
  print_tree(root->right);
}

int main() {

  std::srand(time(nullptr));

  // Determine size
  int sizearray = 5;

  // Create array
  int *arr = create_array(sizearray);

  // Build tree
  Node *root = nullptr;

  Node *tree = create_tree(root, arr, sizearray);
  std::cout << "Tree buildt" << std::endl;

  // Print tree
  print_tree(tree);

  return 0;
}
