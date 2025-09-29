using namespace std;
#include <iostream>

//variabili globali (per debugging)
int n1,n2;

// greatest common factor
int gcf(int &  a,int & b)
{
  int rest;
  while(b!=0) {
    rest = a%b;
    a = b;
    b = rest;
  }
  return a;
}

int main ()
{
  cout << "Insert a pair of numbers:  ";
  cin >> n1 >> n2;
  int res = gcf(n1,n2);
  cout << "The G.C.F. between " << n1 <<
    " and " << n2 <<
    " is " << res << endl;
		return 0;
}
