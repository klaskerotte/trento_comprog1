#include <cstdlib>
#include <iostream>

struct node {
  int data;
  node *left;
  node *right;
};

node *insert_node(node *p, int value) {
  if (p == nullptr)
    return new node{value, nullptr, nullptr};

  if (value > p->data)
    p->right = insert_node(p->right, value);
  else
    p->left = insert_node(p->left, value);

  return p;
}

node *createBST(int *array, int size) {

  node *tree = new node{array[0], nullptr, nullptr};

  for (int i = 1; i < size; i++)
    insert_node(tree, array[i]);

  return tree;
}

void printBT(node *t) {
  if (!t)
    return;
  printBT(t->left);
  std::cout << t->data << std::endl;
  printBT(t->right);
}

void displaytree(node *p, int depth = 0) {
  if (p == nullptr)
    return;
  displaytree(p->right, depth + 1);
  for (int i = 0; i < depth; i++) {
    std::cout << "     ";
  }
  std::cout << p->data << std::endl;
  displaytree(p->left, depth + 1);
}

int *createarray(int size) {
  int *out = new int[size];
  for (int i = 0; i < size; i++)
    out[i] = std::rand() % (10 + 1);
  return out;
}

void printarray(int *array, int s) {
  std::string out = "[";
  for (int i = 0; i < s; i++) {
    out += std::to_string(array[i]);
    out += " ";
  }
  out += "]";
  std::cout << "Array created: " << out << std::endl;
}

int main() {
  std::srand(time(nullptr));

  int sizearray = 6;
  int *a = createarray(sizearray);
  printarray(a, sizearray);

  node *tree = createBST(a, sizearray);

  std::cout << "Tree created" << std::endl;
  displaytree(tree);

  return 0;
}
