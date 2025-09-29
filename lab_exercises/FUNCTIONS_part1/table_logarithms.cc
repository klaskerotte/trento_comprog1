using namespace std;
#include <iostream>
#include <iomanip>  
#include <cmath> 

const float MAX=100.0;

int main () 
{
  
// Print the log table

 cout << "  i     ln(i)  log10(i)   log2(i)\n";
 cout << "---------------------------------\n";
 cout.setf(ios::fixed);  // fixes to the default precision, from here setprecision will set the fractional part only
 
for (float i=1.0;i<=MAX;i+=1.0) {
  cout << setw(3) << setprecision(0)  << i  // setw sets the nr, of characters in output, setprecision sets the precision (fractional since ios::fixed) to 0
       << setprecision(4)  //setprecision sets the precision (fractional since ios::fixed has been used) to 4
       << setw(10) << log(i)	//setw sets the number of characters used on output to 10
       << setw(10) << log10(i)  
       << setw(10) << log(i)/log(2.0) 
       << endl;
}
return 0;
}