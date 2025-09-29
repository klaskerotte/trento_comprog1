using namespace std;
#include <iostream>
#include <cctype>

int main()
{ 
  // EXAMPLE 1
  char c_upper='A';
  char c_lower = tolower(c_upper); //convert 'A' to lowercase
  cout << "(1) " << c_lower << endl;

  // EXAMPLE 2
  int i_upper=65; //ASCII 'A'
  c_lower = tolower(i_upper); //convert 65 in the corresponding ASCII character (i.e.,'A') and then to lowercase
  cout << "(2) " << c_lower << endl;

  // EXAMPLE 3
  i_upper=63; //ASCII '?'
  c_lower = tolower(i_upper); //convert 63 in the corresponding ASCII character (i.e.,'?') and then to lowercase
  cout << "(3) " << c_lower << endl;  //automatic convertion char->int
  cout << "(4) " << tolower(i_upper) << endl; //the int corresponding to '?' is printed (i.e., 63)
  cout << "(5) " << (char) tolower(i_upper) << endl; //the char corresponding to the ASCII dec. code 63 is printed (i.e., '?')

  // EXAMPLE 4
  int ind_c=65;
  c_lower=tolower(ind_c);
  cout << "ind_c= " << ind_c;
  cout << " c_u=" << (char) ind_c << " c_lower=" << c_lower << endl;

  cout << isspace((char)ind_c) << endl;

  return 0;
}
