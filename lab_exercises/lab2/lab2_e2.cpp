#include <iostream>

int main(){

float T_f, T_c;

std::cout << "What is the temperature in Fahrenheit?" << std::endl;
std::cin >> T_f;

T_c = (T_f-32)/1.8;

std::cout << "The temperature in celsius is --->" << T_c << std::endl;

return 0;

}
