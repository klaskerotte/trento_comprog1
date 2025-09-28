#include <iostream>
#include <cmath>

int main(){

int n, a;

std::cout << "input number to raise to power" << std::endl;
std::cin >> a;

std::cout<< "input how many powers from 1?" << std::endl;
std::cin >> n;

for(int i=1; i < n+1; ++i){
	std::cout<<pow(a,i)<<std::endl;
}








return 0;
}