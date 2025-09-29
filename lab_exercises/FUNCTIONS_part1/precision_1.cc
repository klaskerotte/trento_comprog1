using namespace std;
#include <iostream>
#include <iomanip>  // It is used to set fill character (setw). It is used to set decimal precision (setprecision)

int main () 
{
 
// TEST precision/fixed/defaultfloat
 double test = 111.123456789;
 //double test = 3.1234567; //test with this also!
 
 cout << "(1) default precision is:"<< cout.precision() << "; number=" << test  << endl;  //get the default precision of output (6) //111.123 	//3.12346
 
 cout << setprecision(2);  //set the new precision values (both integral and fractional parts)
 cout << "(2) number=" << test  << endl;  //1.1e+02  //3.1
   
 cout << setprecision(7);  //set the new precision values (both integral and fractional parts)
 cout << "(3) number=" << test  << endl; //111.1235 	//3.123457

 cout << setprecision(7) << fixed; //set the new precision values only for the fractional parts
 cout << "(4) number=" << test  << endl; //111.1234568		//3.1234567
 
 cout << setprecision(6) << defaultfloat; //reset to the default (6) precision values (both integral and fractional parts)
 cout << "(5) number=" << test  << endl; //111.123		//3.12346
 
 cout << setprecision(5); //setthe new precision values (both integral and fractional parts)
 cout << "(6) number=" << test  << endl; //111.12	//3.1235
 
 cout << "(7) (fixed) number=" << fixed << test  << endl;  //setprecision(5) applied to the fractional part (i.e., fixed) //111.12346	//3.12346
 cout << "(8) (fixed) number=" << setprecision(4) << test  << endl; //setprecision(4) applied to the fractional part (i.e., fixed) //111.1235	//3.1235
 
 //reset
 cout << setprecision(6) << defaultfloat; //reset to the default (6) precision values (both integral and fractional parts)  
 
 //ios::fixed
 cout.setf(ios::fixed); //from this setprecision will work in the fractional part only
 cout << setprecision(3); //setthe new precision of the fractional parts, since cout.setf(ios::fixed);
 cout << "(9) (ios::fixed) number=" << test  << endl;   //111.123		//3.123
 cout.unsetf(ios::fixed); //reset for the use of setprecision for both integral and integer part
 cout << "(10) number=" << test  << endl;   //111		//3.12
 
 //reset
 cout << setprecision(6) << defaultfloat; //reset to the default (6) precision values (both integral and fractional parts)
 
 //ios::scientific
 cout.setf(ios::scientific);
 cout << setprecision(3); //setthe new precision of the fractional parts, since cout.setf(ios::fixed);
 cout << "(11) (ios::scientific) number=" << test  << endl;  	//	//3.123e+00
 cout.unsetf(ios::scientific);
 
 //reset
 cout << setprecision(6) << defaultfloat; //reset to the default (6) precision values (both integral and fractional parts)
  
 //setw(n)
 cout << "(12) (setw) number=" << test << endl; 			//111.123 (i.e., 7 characters are need)
 cout << "(12a) (setw) number=" << setw(5) << test << endl; 	//111.123 (5 is lower than the needed characters)
 cout << "(12b) (setw) number=" << setw(8) << test << endl; 	// 111.123
 cout << "(12c) (setw) number=" << setw(10) << test << endl; //   111.123
 cout << "(12d) (setw) number=" << setw(12) << test << endl;	//     111.123
 //
 
 return 0;
}

