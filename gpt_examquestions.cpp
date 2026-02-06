#include <iostream>

int main() {
  // 1. A variables definition allocates memory for the variable. The
  // declaration informs the compiler of the variables type.

  // 2. The difference lies in checking the condition. While-loops checks the
  // condition before entering the block, whereas do-while checks the condition
  // on exit, guaranteeing at least one iteration of the block. Example below.

  int a = 1;

  while (a < 1) {
    std::cout << "No print, checked on entry" << std::endl;
    a++;
  };

  do {
    std::cout << "Prints one iteration due to checking condition on exit"
              << std::endl;
    a++;
  }

  while (a < 1);
}

// 3.
