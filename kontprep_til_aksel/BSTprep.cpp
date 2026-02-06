#include <cstdlib>
#include <iostream>

struct node {
  int data;
  node *left;
  node *right;
};

// Insert element function
node *insert_element(node *p, int value) {
  if (p == nullptr)
    return new node{value, nullptr, nullptr};

  if (value > p->data)
    p->right = insert_element(p->right, value);
  else
    p->left = insert_element(p->left, value);

  return p;
}

// Create tree from array function
node *create_tree(int *arr, int arrsize) {

  node *root = new node{arr[0], nullptr, nullptr};
  node *temp = root;

  for (int i = 1; i < arrsize; i++) {
    insert_element(temp, arr[i]);
  }
  return root;
}

void displayBT(node *bt) {
  if (!bt)
    return;

  displayBT(bt->left);
  std::cout << bt->data << std::endl;
  displayBT(bt->right);
}

// Chatgpt display tree
void display_tree(node *p, int depth = 0) {
  if (p == nullptr) {
    return;
  }

  display_tree(p->right, depth + 1);

  for (int i = 0; i < depth; i++) {
    std::cout << "    ";
  }
  std::cout << p->data << std::endl;

  display_tree(p->left, depth + 1);
}

// Create random array of size n in range [0,m]
int *createarray(int n, int m) {
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = std::rand() % (m + 1);
  return arr;
}

void displayarray(int *arr, int size) {
  std::string output = "[";
  for (int i = 0; i < size; i++) {
    output += std::to_string(arr[i]);
    output += " ";
  }
  output += "]";
  std::cout << "Array is = " << output << std::endl;
}

int main() {
  std::srand(time(nullptr));
  int sizearray = 6;
  int range = 10;

  // Create array
  int *myarr = createarray(sizearray, range);
  displayarray(myarr, sizearray);

  // Create tree from array
  node *tree = create_tree(myarr, sizearray);

  // Display tree
  std::cout << "Tree created: " << std::endl;
  display_tree(tree);

  return 0;
}
