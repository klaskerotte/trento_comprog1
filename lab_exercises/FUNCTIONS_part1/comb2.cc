using namespace std;
#include <iostream>

//computation of the factorial
long long fact(int num);
long long comb(int n1,int k1);

int main()
{
  int n,k;
  do {
    cout << "Select n e k (0 0 for ends): " ;
    cin >> n >> k;
    if (n!=0)
      cout << "comb(" << n << "," << k << ") = " << comb(n,k) << endl;
  } while (n!=0);
  return 0;
}


long long comb(int n1,int k1)
{
  long long ris;
  ris = fact(n1);
  ris /=fact(k1);
  ris /=fact(n1-k1); // ris = fact(n1)/(fact(k1)*fact(n1-k1))
  return ris;
}

long long fact(int num)
{
  long long factorial = 1;
  for (int i=1; i<=num; i++)
    factorial *= i;
  return factorial;
}
