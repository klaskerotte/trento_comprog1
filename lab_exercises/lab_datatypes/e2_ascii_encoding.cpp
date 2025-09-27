#include <iostream>

int main(){

char input;

int temp,key;

std::cout << "Input a character" << std::endl;
std::cin >> input;

std::cout << "Input an integer encryption key" << std::endl;
std::cin >> key;

temp = input + key;


char output = temp;

std::cout << "The encoded character is " << output << std::endl;






return 0;
}