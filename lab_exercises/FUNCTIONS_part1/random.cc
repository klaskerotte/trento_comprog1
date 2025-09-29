using namespace std;
#include <iostream>

int main()
{ 
  // EXAMPLE 1
 int v0= rand();     // range 0 to RAND_MAX
 cout << "(v0) " << v0 <<" RAND_MAX=" << RAND_MAX << endl; 

 int v1 = rand() % 100;         // range 0 to 99
 cout << "(v1) " << v1 << endl; 

 int v0b= rand() % 100;       // range 0 to 99
 cout << "(v1b) " << v0b << endl; 

 int v1c= rand()% 100;      // range 0 to 99
 cout << "(v1c) " << v1c << endl; 

 int v2 = rand() % 100 + 1;     // range 1 to 100
 cout << "(v2) " << v2 << endl; 

 int v3 = rand() % 30 + 1985;   // range 1985-2014
 cout << "(v3) " << v3 << endl; 

 int v4 = rand() % (2014-1985+1) + 1985;   // range 1985-2014
 cout << "(v4) " << v4 << endl; 
 
 int v5 = rand() % (100-10+1) + 10;   // range 10-100
 cout << "(v5) " << v5 << endl; 

 int v6 = rand() % (2-0+1) + 0;   // range 1985-2014
 cout << "(v6) " << v6 << endl; 
   v6 = rand() % (2-0+1) + 0;   // range 1985-2014
 cout << "(v6) " << v6 << endl;
   v6 = rand() % (2-0+1) + 0;   // range 1985-2014
 cout << "(v6) " << v6 << endl;
 return 0;
}
