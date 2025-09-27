#include <iostream>

int main(){

char input;
int upper_lower_diff = 97-65;
char output;

std::cout<< "Initializing and running, what is the character you want to convert?" << std::endl;

std::cin >> input;
int ascii = input;

if (ascii >= 65 and ascii <= 90){
	output = ascii + upper_lower_diff;
	}
else{
	std::cout<<"No characters were to be converted" <<std::endl;
	}

std::cout<< output;

}