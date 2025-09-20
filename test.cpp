#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <iomanip>
using namespace std;

// Utility: print vector nicely with spacing
void printVector(const vector<double> &v, int offset = 0, int width = 4)
{
    for (int i = 0; i < offset; i++)
        cout << string(width, ' ');
    for (double val : v)
    {
        cout << setw(width) << val;
    }
    cout << endl;
}

vector<double> convolutionAnimatedGraphical(const vector<double> &x1, const vector<double> &x2)
{
    int n1 = x1.size();
    int n2 = x2.size();
    int ny = n1 + n2 - 1;

    vector<double> y(ny, 0.0);

    for (int n = 0; n < ny; n++)
    {
        cout << "\nStep n = " << n << "\n";

        // Print x2 shifted to position n
        int offset = n;
        printVector(x2, offset);

        // Print x1 below it
        printVector(x1);

        cout << "Computing y[" << n << "]...\n";

        double sum = 0;
        for (int k = 0; k < n1; k++)
        {
            if (n - k >= 0 && n - k < n2)
            {
                double term = x1[k] * x2[n - k];
                sum += term;
                cout << "  x1[" << k << "] * x2[" << (n - k) << "] = "
                     << x1[k] << " * " << x2[n - k]
                     << " = " << term << "  (partial sum = " << sum << ")\n";
                this_thread::sleep_for(chrono::milliseconds(500));
            }
        }

        y[n] = sum;
        cout << "=> y[" << n << "] = " << sum << endl;
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return y;
}

int main()
{
    // Example arrays (replace with input if needed)
    vector<double> x1 = {1, 2, 3};
    vector<double> x2 = {4, 5, 6};

    cout << "Animated Graphical Convolution:\n";
    vector<double> y = convolutionAnimatedGraphical(x1, x2);

    cout << "\nFinal Convolution Result: ";
    for (double val : y)
        cout << val << " ";
    cout << endl;

    return 0;
}
