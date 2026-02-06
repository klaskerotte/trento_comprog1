#include <cstdlib>
#include <iostream>
#include <string>

int *create_array(int rows, int columns) {

  std::cout << "creating array" << std::endl;
  int size = rows * columns;
  int *array = new int[size];

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      array[j + i * columns] = std::rand() % 11;
    }
  }

  return array;
}

void display_array(int *array, int rows, int columns) {
  std::cout << "displaying array" << std::endl;
  std::string output;

  for (int i = 0; i < rows; i++) {
    output += "[";
    for (int j = 0; j < columns; j++) {
      output += std::to_string(array[j + i * columns]);
      output += " ";
    }
    output += "]\n";
  }
  std::cout << output << std::endl;
}

int main(int argc, char *argv[]) {
  std::srand(time(nullptr));

  int rows = std::atoi(argv[1]);
  int columns = std::atoi(argv[2]);

  int *array = create_array(rows, columns);

  display_array(array, rows, columns);

  int fy, fx, subrows, subcolumns;
  std::cout << "What is your first coordinate? (a b)" << std::endl;
  std::cin >> fx >> fy;

  std::cout << "How big is your submatrix? (row col)" << std::endl;
  std::cin >> subrows >> subcolumns;

  // calculate the actual end coordinates, clamping to matrix size
  int endx = std::min(fx + subcolumns, columns);
  int endy = std::min(fy + subrows, rows);

  std::string output;
  for (int i = fy; i < endy; i++) {
    output += "[";
    for (int j = fx; j < endx; j++) {
      output += std::to_string(array[j + i * columns]);
      output += " ";
    }
    output += "]\n";
  }

  std::cout << "SUB" << std::endl;
  std::cout << output << std::endl;

  delete[] array;

  return 0;
}
