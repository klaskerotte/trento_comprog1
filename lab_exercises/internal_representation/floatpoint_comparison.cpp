#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float a = 0.3;
    float b = 0.1 + 0.2;

    float epsilon = 1e-6; // tolerance

    if (fabs(a - b) < epsilon) {
        cout << "a and b are approximately equal" << endl;
    } else {
        cout << "a and b are NOT equal" << endl;
    }
}
