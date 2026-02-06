#include <cstdlib>
#include <iostream>
#include <string>

// Make a function that takes an array of integers and its size and
// builds a binary tree

// Define the Node structure
struct Node {
  int data;
  Node *left;
  Node *right;
};

// Function to create array of random integers
int *create_rand_array(int size) {

  std::string output = "[";
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = std::rand() % 11;
    output += std::to_string(array[i]);
    output += " ";
  }
  output += "]";
  std::cout << "Array created: " << output << std::endl;

  return array;
}

// Function to insert Node in binary tree
Node *insert_node(Node *root, int value) {

  if (!root)
    return new Node{value, nullptr, nullptr}; // If no root exists, create one

  if (value > root->data) // If the value is greater than the root go right
    root->right = insert_node(
        root->right, value); // Recursively jump right until it is not bigger
}
else {
  root->left = insert_node(root->left, value); // Same for lesser values
}

return root;
}

Node *create_tree(Node *root, int *array, int size) {

  for (int i = 0; i < size; i++) {
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

  Node *root = nullptr;
  int sizearray = 5;
  int *arr = create_rand_array(sizearray);

  Node *tree = create_tree(root, arr, sizearray);
  print_tree(tree);

  delete root;
  delete tree;
  delete arr;
  return 0;
}
