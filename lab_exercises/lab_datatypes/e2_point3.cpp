#include <iostream>
#include <iomanip>



int main(){

float var = 0.1;

float output = var+var+var;

std::cout << std::setprecision(5) << std::showpoint << output << std::endl;

return 0;
}