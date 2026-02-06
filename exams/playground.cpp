#include <cstdlib>
#include <iostream>

void insertionsort(int *arr, int size) {

  std::cout << "Sorting array of size: " << size << std::endl;
  for (int i = 1; i < size; i++) {

    int key = arr[i];
    int j = i - 1;

    while ((j >= 0) && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void display_array(int *arr, int mysize) {
  for (int i = 0; i < mysize; i++)
    std::cout << arr[i] << std::endl;
}

int *create_array(int size) {

  std::cout << "Creating array of size: " << size << std::endl;

  int *arr = new int[size];

  for (int i = 0; i < size; i++)
    arr[i] = std::rand() % 10;

  return arr;
}

int main(int argc, char *argv[]) {

  // Take size from user to create dynamically allocated array
  int size = std::atoi(argv[1]);

  // Create the array
  int *myarray = create_array(size);
  std::cout << "Array of size: " << size << " was created" << std::endl;

  display_array(myarray, size);

  // Sort the array
  insertionsort(myarray, size);
  display_array(myarray, size);

  delete[] myarray;

  return 0;
}
