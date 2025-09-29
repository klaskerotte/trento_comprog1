//  Example 4.20, page 110
//  Schaum's Outline of Programming with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1996

using namespace std;
#include <iostream>

void f();
void g();
void h();
int x = 11;              // this x is global

int main()
{                        // begin scope of main()
  cout << "In main(): x = " << x << endl;  //11
  int x = 22;
  {                      // begin scope of internal block
    int x = 33;		
    cout << "In block inside main(): x = " << x << endl;  //33
  }                      // end scope of internal block
  cout << "In main(): x = " << x << endl; //22
  f();
  g();
  for(int x = 0; x < 4; x++) {
    h();
  }
  return 0;
}                        // end scope of main()

void f()
{                        // begin scope of f()
  int x = 44;
  cout << "In f(): x = " << x << endl;	//44
}                        // end scope of f()

void g()
{                        // begin scope of g()
  cout << "In g(): x = " << x << endl; //11
}                        // end scope of g()

void h() {
  static int x = 10; //allocated the first time for the whole life-cycle of the program (but is it always a local variable) //what happens without "static" .. //10 .. //10 .. //10 .. //10

  cout << "in h(): x = " << x++ << endl;  //10 .. //11 .. //12 .. //13
}
