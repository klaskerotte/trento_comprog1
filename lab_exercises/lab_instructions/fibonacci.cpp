#include <iostream>

int main(){ 

int a,b,n,temp;	


std::cout<<"How many fibonacci numbers do you want to compute?"<<std::endl;
std::cin>>n;


a = 0;
b = 1;

for(int i = 0; i < n; ++i){
std::cout<<a<<std::endl;
temp = a+b;
a = b;
b = temp;

}

return 0;
}