#ifndef BSTFUNCTIONS
#define BSTFUNCTIONS

struct node {
  int data;
  node *left;
  node *right;
};

int *createarray(int size);
void printarray(int *array, int size);
node *insert_element(node *tree, int value);
node *createBST(int *array, int size);
void fancyprintBST(node *tree, int depth);

#endif // BSTFUNCTIONS
