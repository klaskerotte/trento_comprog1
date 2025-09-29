using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath> //log10


// computes the logarithmic base ten of x double mylog10(double x)
double mylog10(double x)
{
  double y = log(x)/log(10.0);
  return y;
}

int main () {
  const double Eps = 1.0e-10;
  double log,mylog;
  cout.setf(ios::fixed);

  cout << "--------------------------------------------------\n";
  cout << "                      log10   mylog10\n";
  cout << "--------------------------------------------------\n";

  for (double i=1.0;i<=100.0;i+=2.0) {
    log=log10(i);
    mylog=mylog10(i);
    cout << setprecision(1) //4 vs. 20
         << "log10(" << setw(8) << i << ") ="
         << setw(10) << log << "  "
         << setw(10) << mylog;
     //if (log==mylog)  //try!
	 //if (fabs((log-mylog))<=Eps)  //try
     if (fabs((log-mylog))<=fabs(log*Eps)) 
      cout << "  Equal!";
    else
      cout << "  Different! The difference is " << log-mylog;
    cout  << endl;
  }
  return 0;
}
