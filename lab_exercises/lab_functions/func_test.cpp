#include <iostream>

int dividebytwo(int num){

num = num/2;

return num;
}

int main(){

int num = 10;

num = dividebytwo(num);

std::cout<<num<<std::endl;

return 0;

}