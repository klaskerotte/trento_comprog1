#include "BSTFUNCTIONS.h"
#include <cstdlib>
#include <iostream>

int main() {
  std::srand(time(nullptr));
  int arrsize = 20;
  int *arr = createarray(arrsize);
  printarray(arr, arrsize);

  node *tree = createBST(arr, arrsize);
  fancyprintBST(tree, 0);

  return 0;
}
