using namespace std;
#include <iostream>

int gcd(int, int); //what happens without this function declaration? ..compile-time error!

int main()
{
	int res=gcd(24,36);
	cout << res << endl;
}

int gcd(int a, int b){
	return 12;
}
