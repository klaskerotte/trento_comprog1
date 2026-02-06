#include <cstdlib>
#include <iostream>
#include <string>

struct Node {
  int data;
  Node *left;
  Node *right;
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
  std::cout << "Array created: " << output << std::endl;
  return array;
}

Node *insert_node(Node *root, int value) {

  if (!root)
    return new Node{value, nullptr, nullptr};

  if (value > root->data) {
    root->right = insert_node(root->right, value);
  } else {
    root->left = insert_node(root->left, value);
  }
  return root;
}

Node *create_tree(Node *root, int *array, int size) {

  for (int i = 0; i < size; i++)
    root = insert_node(root, array[i]);

  return root;
}

void display_tree(Node *root) {

  if (root == nullptr)
    return;

  display_tree(root->left);
  std::cout << root->data << std::endl;
  display_tree(root->right);
}

int main(int argc, char *argv[]) {

  // Set seed
  std::srand(time(nullptr));

  // Determine arraysize
  int size = std::atoi(argv[1]);

  // Create array
  int *arr = create_array(size);

  // Build tree

  Node *treeroot = nullptr;
  Node *tree = create_tree(treeroot, arr, size);

  // Display tree
  std::cout << "Current tree state: " << std::endl;
  display_tree(tree);

  return 0;
}
