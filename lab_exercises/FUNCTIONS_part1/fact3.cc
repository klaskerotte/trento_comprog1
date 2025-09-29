using namespace std;
#include <iostream>

//compuation of the factorial

long long fact(int num)
{
  long long factorial = 1;
  for (int i=1; i<=num; i++)
    factorial *= i;
  return factorial;
}

int main()
{
  int  num;
  long long factorial;

  cout << "Insert a number: ";
  cin >> num;
  factorial=fact(num);
  cout  << "Fact = "  << factorial   << endl;
  return 0;
}
