#include <cstdlib>
#include <fstream>
#include <iostream>

int main(int argc, char *argv[]) {

  // Initialize input and output filestream
  std::ifstream f1(argv[1]);
  std::ofstream f2(argv[2]);

  std::cout << f1.is_open() << std::endl;
  std::cout << f2.is_open() << std::endl;

  // Reading from f1 keeps whitespaces and newlines.
  f1 >> std::noskipws;

  char c;
  bool capitalize = true;

  while (f1 >> c) {
    if (capitalize && (c >= 'a') && (c <= 'z')) {
      c = c - ('a' - 'A');
      capitalize = false;
    }

    if ((c == '?') || (c == '!') || (c == '.'))
      capitalize = true;

    f2 << c;
  }

  f1.close();
  f2.close();
  std::cout << f1.is_open() << std::endl;
  std::cout << f2.is_open() << std::endl;
}
