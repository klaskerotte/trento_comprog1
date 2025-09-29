#include <iostream>
#include <cstdlib>

int main(){

srand(time(NULL));

int a = rand()%(100+1);

std::cout<<a<<std::endl;

int t = time(nullptr);
std::cout<<t<<std::endl;

return 0;
}