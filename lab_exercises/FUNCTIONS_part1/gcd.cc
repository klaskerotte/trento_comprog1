using namespace std;
#include <iostream>

int gcd(int a, int b){
    int remainder;
    while(b!=0) {
        remainder = a%b;
        a = b;
        b = remainder;
    }
    return a;
}


int main () 
{
  int n1, n2;
  cout << "Insert two Integer numbers: "<< endl;  
  cin >> n1 >> n2;
  int gcdValue = gcd(n1,n2);
  cout << "GCD = "<< gcdValue << endl;  
  
  
return 0;
}