using namespace std;
#include <iostream>

//global variables (per debugging)
int n1,n2;

// greatest common factor
int gcf(int  a,int  b) 
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
  cout << "Insert a pair of numbers: ";
  cin >> n1 >> n2;
  cout << "The G.C.F. between " << n1 << 
    " and " << n2 <<
    " is " << gcf(n1,n2) << endl;
return 0;
}
