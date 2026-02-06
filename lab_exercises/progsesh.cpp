#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <vector>

bool notpq(bool a, bool b)
{
    return (!a || b);
}

double absval_with_cmath(double a, double b)
{
    return abs(a - b);
}

double absval_wo_cmath(double a, double b)
{
    if (a - b < 0)
    {
        return (a - b) * (-1);
    }
    else
        return (a - b);
}

int fibonacci(unsigned int n)
{
    unsigned int F_0 = 0;
    unsigned int F_1 = 1;

    unsigned int fibonacci_sequence[n];

    for (unsigned int i = 0; i < n; i++)
    {
        switch (i)
        {
        case 0:
            fibonacci_sequence[i] = F_0;
            std::cout << fibonacci_sequence[i] << std::endl;
            continue;
        case 1:
            fibonacci_sequence[i] = F_1;
            std::cout << fibonacci_sequence[i] << std::endl;
            continue;
        }
        fibonacci_sequence[i] = fibonacci_sequence[i - 1] + fibonacci_sequence[i - 2];
        std::cout << fibonacci_sequence[i] << std::endl;
    }
    return 0;
}

void reverseArray(std::string &arr)
{

    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        std::swap(arr[left], arr[right]);

        left++;
        right--;
    }
    std::cout << "The reversed string is " << arr << std::endl;
}

int binaryToDecimal(std::string binarynum)
{
    int decimalnum = 0;

    reverseArray(binarynum);

    for (int i = 0; i < size(binarynum); i++)
    {
        std::cout << binarynum[i] << std::endl;
        int bit = binarynum[i] - '0';
        decimalnum += bit * pow(2, i);
    }
    return decimalnum;
}

void pyramidart(int height)
{
    for (int i = 0; i < height; i++)
    {
        char canvas[height][height];
        for (char a : canvas)
        {
            a = ' '
        }
    }
}

int main()
{

    pyramidart(3);

    return 0;
}
