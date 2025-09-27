#include <iostream>
#include <cctype>


int main(){

char input,output;
int diff;

diff = 'a'-'A';

std::cout << "Input a lowercase character to convert" << std::endl;
std::cin >> input;

if (input < 97 || input > 122){
	std::cout << "Smart ass" << std::endl;
	}

output = input-diff;

std::cout << output << std::endl;

std::cout << "\nUsing the 'toupper()' function from the cctype library yields" << std::endl;
std::cout << (char)toupper(input) << std::endl;


return 0;
}