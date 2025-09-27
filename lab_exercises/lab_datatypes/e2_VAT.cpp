#include <iostream>
#include <iomanip>

int main(){

std::cout <<"\nInitializing GROSS, VAT, NET...\n" << std::endl;
float GROSS, VAT, NET;

int n = 5;
std::cout << "Digit precision is set to -----> " << n << std::endl;


VAT = 3.123123132;
NET = 20.123123123;

GROSS = (1+VAT) * NET;

std::cout << "VAT and NET set to " << std::setprecision(5) << std::showpoint << VAT << " " << NET << std::endl;


std::cout << "\nThe GROSS cost is then..." << std::endl;
std::cout  << std::setprecision(5) << std::showpoint << GROSS << std::endl;

}