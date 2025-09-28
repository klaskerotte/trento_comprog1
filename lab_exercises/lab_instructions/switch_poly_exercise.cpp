#include <iostream>
#include <cmath>

int main(){

float a,b,c,x1real,x2real,x1im,x2im;

std::cout<< "input a, b, and c" << std::endl;

std::cin >> a;
std::cin >> b;
std::cin >> c;

float delta = pow(b,2) - 4*a*c;

switch (delta < 0){
	case 0:
	std::cout << "delta < 0" << std::endl;
	x1real = (-b/(2*a));
	x1im = sqrt(abs(delta)/(2*a));
	std::cout<< "The result is X_1 = " << x1real <<" + " << x1im << "i" << std::endl;
	std::cout<< "And X_2 = " << x1real <<" - " << x1im << "i" << std::endl;
	
	break;
	
	case 1:
	std::cout << "delta > 0" << std::endl;
	x1real = (-b/(2*a));
	x1im = sqrt(abs(delta)/(2*a));
	std::cout<< "The result is X_1 = " << x1real + x1im << std::endl;
	std::cout<< "And X_2 = " << x1real - x1im << std::endl;
	break;

return 0; 
}
}