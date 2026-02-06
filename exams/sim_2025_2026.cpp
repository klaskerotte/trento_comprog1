#include <cmath>
#include <iostream>

void displayarray(int *arr, int size) {
  std::string disp = "[";
  std::cout << "The array is: " << std::endl;
  for (int i = 0; i < size; i++) {
    disp += std::to_string(arr[i]);
    disp += ' ';
  }
  disp += "]\n";
  std::cout << disp << std::endl;
}

int *mergearrays(int *arr1, int size1, int *arr2, int size2) {

  int *mergedarray = new int[size1 + size2];
  for (int i = 0; i < size1; i++)
    mergedarray[i] = arr1[i];
  for (int j = size1; j < size1 + size2; j++)
    mergedarray[j] = arr2[j - size1];

  return mergedarray;
}

void insertionsort(int *arr, int size) {

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

float arr_median(int *arr, int size) {

  if ((size % 2) == 0) {
    float midleft = arr[(size) / 2];
    float midright = arr[(size) / 2 - 1];
    return (midleft + midright) / 2;

  } else
    return arr[(size - 1) / 2];
}

float arr_average(int *arr, int size) {
  float sum;
  for (int i = 0; i < size; i++)
    sum += arr[i];
  return sum / size;
}

int arr_minimum(int *arr, int size) {
  int min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] < min) {
      min = arr[i];
    }
  }
  return min;
}

int arr_maximum(int *arr, int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int arr_sum(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++)
    sum += arr[i];
  return sum;
}

int *create_rand_array(int size) {

  int *arr = new int[size];
  for (int i = 0; i < size; i++)
    arr[i] = std::rand() % 11;
  return arr;
}

int main() {
  // Set random seed
  std::srand(time(NULL));

  // Decide size of array 1 and 2;
  int size1 = 10;
  int size2 = 5;

  // Create the corresponding arrays with random integers between 0 and 10;
  int *array1 = create_rand_array(size1);
  int *array2 = create_rand_array(size2);

  // Display the arrays
  displayarray(array1, size1);
  displayarray(array2, size2);

  // Create merged array
  std::cout << "Merging arrays...." << std::endl;
  int sizemerged = size1 + size2;
  int *mergedarray = mergearrays(array1, size1, array2, size2);
  displayarray(mergedarray, sizemerged);

  // Sort the array
  std::cout << "Sorting array..." << std::endl;
  insertionsort(mergedarray, sizemerged);
  displayarray(mergedarray, sizemerged);

  // Calculate median
  std::cout << "The median is: " << arr_median(mergedarray, sizemerged)
            << std::endl;

  // Calculate average
  std::cout << "The average is: " << arr_average(mergedarray, sizemerged)
            << std::endl;
  ;

  // Find minimum
  std::cout << "The minimum is: " << arr_minimum(mergedarray, sizemerged)
            << std::endl;
  ;

  // Find maximum
  std::cout << "The maximum is: " << arr_maximum(mergedarray, sizemerged)
            << std::endl;
  ;

  // Calculate the sum
  std::cout << "The sum is: " << arr_sum(mergedarray, sizemerged) << std::endl;

  delete[] mergedarray;

  return 0;
}
