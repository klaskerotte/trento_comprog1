#include <iostream>

int main(){
std::cout << "\nLook at this shit cuh" << std::endl;
std::cout << "-----------------------------" << std::endl;

bool t = 1;
bool f = 0;

std::cout << "\nAND operator" << std::endl;
std::cout << "-----------------------------" << std::endl;

std::cout << "Input A| Input B| Output" << std::endl;

std::cout << f << "\t" << f << "\t" << (f && f) << std::endl;
std::cout << t << "\t" << f << "\t" << (t && f) << std::endl;
std::cout << t << "\t" << t << "\t" << (t && t) << std::endl;
std::cout << "-----------------------------" << std::endl;

std::cout << "\n" << std::endl;
std::cout << "\nOR operator" << std::endl;
std::cout << "-----------------------------" << std::endl;
std::cout << "Input A| Input B| Output" << std::endl;

std::cout << f << "\t" << f << "\t" << (f || f) << std::endl;
std::cout << t << "\t" << f << "\t" << (t || f) << std::endl;
std::cout << t << "\t" << t << "\t" << (t || t) << std::endl;
std::cout << "-----------------------------" << std::endl;

std::cout << "\n" << std::endl;
std::cout << "\nXOR operator" << std::endl;
std::cout << "-----------------------------" << std::endl;
std::cout << "Input A| Input B| Output" << std::endl;

std::cout << f << "\t" << f << "\t" << (f ^ f) << std::endl;
std::cout << t << "\t" << f << "\t" << (t ^ f) << std::endl;
std::cout << t << "\t" << t << "\t" << (t ^ t) << std::endl;
std::cout << "-----------------------------" << std::endl;

return 0;

}