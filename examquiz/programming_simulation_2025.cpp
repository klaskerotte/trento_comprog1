#include <iostream>

// Merge two arrays into 1
void merge_arrays(int *array1, int length1, int *array2, int length2,
                  int *merged_array) {

  for (int i = 0; i < length1; i++) {
    merged_array[i] = array1[i];
  }
  for (int j = length1; j < length1 + length2; j++) {
    merged_array[j] = array2[j - length1];
  }

  for (int a = 0; a < length1 + length2; a++)
    std::cout << merged_array[a] << std::endl;
}

// Sort array
void sort_array(int *array, int array_length) {
  for (int i = 0; i < array_length - 1; i++) {
    for (int j = 0; j < array_length - i - 1; j++) {
      int temp = 0;
      if (array[j + 1] < array[j]) {
        temp = array[j + 1];
        array[j + 1] = array[j];
        array[j] = temp;

      } else {
        continue;
      }
    }
  }
}

int main() {
  int array1[] = {1, 2, 3, 4, 5};
  int array2[] = {6, 5, 4};

  int length1 = sizeof(array1) / sizeof(array1[0]);
  int length2 = sizeof(array2) / sizeof(array2[0]);

  int merged_array[length1 + length2];

  merge_arrays(array1, 5, array2, 3, merged_array);
  sort_array(merged_array, length1 + length2);
  for (int i = 0; i < length1 + length2; i++)
    std::cout << "\n" << merged_array[i] << std::endl;

  return 0;
}
