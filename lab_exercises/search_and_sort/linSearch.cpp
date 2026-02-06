#include <iostream>

/*
 *
 *
 *
 *
 * Script for linear search
 *
 *
 *
 */

int linearSearch(int *arr, int size, int element) {
  int index;
  for (int i = 0; i < size; i++) {
    if (arr[i] == element) {
      index = i;
      break;
    }
  }

  return index;
}

bool linsearch(int &arr, int size, int element) {

  int main() {
    int testarr[5] = {1, 2, 3, 4, 5};

    int index = linearSearch(testarr, 5, 3);
    std::cout << index << std::endl;
  }
