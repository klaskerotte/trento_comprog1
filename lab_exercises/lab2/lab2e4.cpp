#include <iostream>

int main(){

int hour, minute, second;
int hoursec, minutesec;
int midnight = 60*60*24;


std::cout << "Type in the hour, minute and second" << std::endl;
std::cin >> hour;
std::cin >> minute;
std::cin >> second;

hoursec = hour*60*60;
minutesec = minute*60;

int remaining = midnight - (hoursec + minutesec + second);

std::cout << "The time is " << hour << ":" << minute << ":" << second << std::endl;
std::cout << "And it remains " << remaining << " seconds to midnight " << std::endl;

return 0;


}