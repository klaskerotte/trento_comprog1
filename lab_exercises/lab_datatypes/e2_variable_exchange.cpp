#include <iostream>

int main() {


int min,max,temp;

std::cout << "Input min" << std::endl;
std::cin >> min;

std::cout << "Input max" << std::endl;
std::cin >> max;

if (min > max){
	std::cout << "Dumbass you typed the wrong order" << std::endl;
	temp = max;	
	max = min;
	min = temp;
	}

std::cout << "min is now set to "<< min << " and max is set to " << max << std::endl;

return 0;
}