// example of function composition 
// computation of the min and max among 4 integer numbers

using namespace std;
#include <iostream>

int n1, n2, n3, n4, m1, m2;
// (for debugging)

int mymax(int x, int y)
{
  if (x < y)
    return y;
  else
    return x;
}

int mymin(int x, int y)
{
  if (x > y)
    return y;
  else
    return x;
}

int main()
{
  cout << "Insert 4 integers :";
  cin >> n1 >> n2 >> n3 >> n4;
  m1 =  mymax(mymax(n1,n2),mymax(n3,n4));
  m2 =  mymin(mymin(n1,n2),mymin(n3,n4));

  cout << "Max: " << m1 << ", Min: " << m2 << endl;
  return 0;
}
