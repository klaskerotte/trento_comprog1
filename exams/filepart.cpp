#include <cmath>
#include <fstream>
#include <iostream>

int *createYarrays(std::string &filename, int &count) {

  // Read file
  std::ifstream file(filename);

  // Create line container
  std::string line;

  count = 0;
  // Count lines
  while (std::getline(file, line)) {
    count++;
  }

  int *y = new int[count];

  file.clear();
  file.seekg(0);

  int i = 0;
  while (std::getline(file, line)) {
    y[i] = static_cast<int>(line.length());
    i++;
  }

  return y;
}

int main(int argc, char *argv[]) {

  std::string filename = "test.txt";
  int size = 3;

  int *arr = createYarrays(filename, size);
  if (arr != nullptr) {
    for (int i = 0; i < size; i++)
      std::cout << arr[i] << std::endl;
  }

  delete[] arr;

  return 0;
}
