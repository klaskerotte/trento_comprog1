#include <cmath>
#include <iostream>

void merge_and_sort_arrays(int *arr1, int size1, int *arr2, int size2,
                           int *merged) {

  // Create merged array
  for (int i = 0; i < size1; i++) {
    merged[i] = arr1[i];
  }

  for (int j = size1; j < (size1 + size2); j++) {
    merged[j] = arr2[j - size1];
  }

  // Sort the array

  for (int i = 1; i < size1 + size2; i++) {
    int key = merged[i];
    int j = i - 1;

    while ((j >= 0) && merged[j] > key) {
      merged[j + 1] = merged[j];
      j--;
    }

    merged[j + 1] = key;
  }
}

// Function to find minimum
int array_min(int *array, int sizearray) {
  int temp = array[0];
  for (int i = 0; i < sizearray; i++) {
    if (array[i] < temp)
      temp = array[i];
  }
  return temp;
}

// Function to find maximum
int array_max(int *array, int sizearray) {
  int temp = array[0];
  for (int i = 0; i < sizearray; i++) {
    if (array[i] > temp)
      temp = array[i];
  }
  return temp;
}

// Sorting algo
void bubble_sort(int *arr, int sizearr) {
  for (int i = 0; i < sizearr - 1; i++) {
    for (int j = 0; j < sizearr - i - 1; j++) {
      int temp;
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

// Function to find median of array
int array_median(int *array, int sizearray) {
  // sort the array
  bubble_sort(array, sizearray);

  // Find middle point(s)
  if (sizearray % 2 == 0) {
    int mid_left = array[sizearray / 2 - 1];
    int mid_right = array[sizearray / 2];
    int median = (mid_left + mid_right) / 2;
    return median;
  } else {
    return array[(sizearray - 1) / 2];
  }
}

// Function to find mean of array
float array_mean(int *arr, int sizearr) {
  float sum = 0;
  for (int i = 0; i < sizearr; i++)
    sum += arr[i];

  float result = sum / sizearr;
  return result;
}

// Function to sum the array
float array_sum(int *arr, int sizearr) {
  float sum = 0;
  for (int i = 0; i < sizearr; i++)
    sum += arr[i];
  return sum;
}

int main() {

  // Create first array
  int array1[] = {1, 10, 19, 6, 45};
  int sizearr1 = sizeof(array1) / sizeof(array1[0]);
  for (int i = 0; i < sizearr1; i++)
    std::cout << array1[i] << std::endl;
  std::cout << "----------------------" << std::endl;

  // Create second array
  int array2[] = {50, 14, 1, 35, 2, 5};
  int sizearr2 = sizeof(array2) / sizeof(array2[0]);
  for (int j = 0; j < sizearr2; j++)
    std::cout << array2[j] << std::endl;
  std::cout << "----------------------" << std::endl;

  int size_merged = sizearr1 + sizearr2;

  // Declare merged array
  int mergedarray[size_merged];
  merge_and_sort_arrays(array1, sizearr1, array2, sizearr2, mergedarray);

  // Output merged array
  for (int i = 0; i < size_merged; i++)
    std::cout << mergedarray[i] << std::endl;

  // Output minimum of merged array;
  std::cout << "The minimum of the merged array is: "
            << array_min(mergedarray, size_merged) << std::endl;

  // Output maximum of merged array;
  std::cout << "The maximum of the merged array is: "
            << array_max(mergedarray, size_merged) << std::endl;

  // Output median of the array
  std::cout << "The median of the merged array is: "
            << array_median(mergedarray, size_merged) << std::endl;

  // Output mean of the array
  std::cout << "The mean of the merged array is: "
            << array_mean(mergedarray, size_merged) << std::endl;

  // Output sum of the array
  std::cout << "The sum of the merged array is: "
            << array_sum(mergedarray, size_merged) << std::endl;

  return 0;
}
