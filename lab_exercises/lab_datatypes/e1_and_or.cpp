#include <iostream>

int main(){

bool t = 1;
bool f = 0;

std::cout << "Input A| Input B| Output" << std::endl;

std::cout << f << "\t" << f << "\t" << (f && f) << std::endl;
std::cout << t << "\t" << f << "\t" << (t && f) << std::endl;
std::cout << t << "\t" << t << "\t" << (t && t) << std::endl;

return 0;

}