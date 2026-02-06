#include <cstdlib>
#include <iostream>

int *create_array(int size) {
  int *arr = new int[size];

  for (int i = 0; i < size; i++)
    arr[i] = std::rand() % (10 + 1);
  return arr;
}

void display_array(int *&arr, int size) {
  std::string disp = "[";
  for (int i = 0; i < size; i++) {
    disp += std::to_string(arr[i]);
    disp += " ";
  }
  disp += "]";
  std::cout << disp << std::endl;
}

void check_for_pattern(int *&text, int size, int *&pattern, int sizepattern) {

  bool flag = false;

  for (int i = 0; i < size - sizepattern; i++) {
    int sum = 0;
    for (int j = 0; j < sizepattern; j++) {
      if (text[i + j] == pattern[j])
        sum++;
    }
    if (sum == sizepattern) {
      std::cout << "Pattern found at index " << i << std::endl;
      flag = true;
    }
  }
  if (!flag)
    std::cout << "Pattern was not found " << std::endl;
}

int main() {

  std::srand(time(nullptr));

  int patternsize = 2;
  int textsize = 100;

  int *pattern = create_array(patternsize);
  int *text = create_array(textsize);

  display_array(pattern, patternsize);
  display_array(text, textsize);

  check_for_pattern(text, textsize, pattern, patternsize);

  delete[] pattern;
  delete[] text;
}
