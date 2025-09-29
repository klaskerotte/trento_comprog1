#include <iostream>
#include <cstdlib>

int main(){

// random number
int r_val = rand();

// random number between [0,N-1]
int p_val = rand() % 100;

// random number in range of [min,max]
int range_val = rand() % (150 - 125 + 1) + 125;

// random number in range [-min, max]
int minusminmax = 10 + rand() % (100 - 10 + 1);

std::cout<<r_val<<std::endl;
std::cout<<p_val<<std::endl;
std::cout<<range_val<<std::endl;
std::cout<<minusminmax<<std::endl;

return 0;
}