#include <iostream>
using namespace std;

#include "fact4.h"
// long long fact(int);

int main()
{
  int  num;
  long long factorial;

  cout << "Insert the number: ";
  cin >> num;
  factorial=fact(num);
  cout  << "Fact = "  << factorial   << endl;
  return 0;
}
