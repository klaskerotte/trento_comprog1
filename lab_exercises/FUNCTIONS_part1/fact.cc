using namespace std;
#include <iostream>

//computation of the factorial
//f(0)=1
//f(1)=1
//f(2)=2*1=2
//f(3)=3*2*1=6
//f(4)=4*3*2*1=24
//...

long long fact(int x) 
{
  long long fact_var = 1;
  for (int i=1; i<=x; i++)
    fact_var *= i;
  return fact_var;
}


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
