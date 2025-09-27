#include <iostream>

int main(){

float r;

std::cout<< "please input wanted radius" << std::endl;

std::cin >> r;

float A = r*r*3.14;
float C = 2*3.14*r;


std::cout << "The area is --->" << A << std::endl;
std::cout << "The circumference is --->" << C << std::endl;

return 0;
 
}