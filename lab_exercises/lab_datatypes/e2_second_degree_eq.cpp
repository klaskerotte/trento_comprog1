#include <iostream>
#include <cmath>

int main(){

float a,b,c;
float x1,x2;

std::cout << "Input a,b and c" << std::endl;

std::cin >> a;
std::cin >> b;
std::cin >> c;

if(a == 0 || b==0 ||c == 0){
	std::cout << "Please input only non-zero values for a, b, and c." << std::endl;
	}
else{
	std::cout << "\nLets get this bread" << std::endl;
	}

float delta = pow(b,2) -4*a*c;
if (delta<0){
	std::cout << "The equation has no real solution" << std::endl;
	}
else{
	x1 = (-b+sqrt(delta))/(2*a);
	x2 = (-b-sqrt(delta))/(2*a);
	std::cout << "x_1 = " << x1 << std::endl;
	std::cout << "x_2 = " << x2 << std::endl;
	}


return 0;

}