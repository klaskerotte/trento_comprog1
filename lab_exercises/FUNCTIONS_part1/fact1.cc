using namespace std;
#include <iostream>

//computation of the factorial
long long fact(int x);

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

long long fact(int x)
{
  long long fact_var = 1;
  for (int i=1; i<=x; i++)
    fact_var *= i;
  return fact_var;
}
