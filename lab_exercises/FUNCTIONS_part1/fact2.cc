using namespace std;
#include <iostream>

int  num;
long long factorial;

//computation of the factorial
long long fact(int x)
{
  long long factorial = 1;
  for (int i=1; i<=x; i++)
    factorial *= i;
  return factorial;
}

int main()
{
  cout << "Insert the number: ";
  cin >> num;
  factorial=fact(num);
  cout  << "Fact = "  << factorial   << endl;
  return 0;
}
