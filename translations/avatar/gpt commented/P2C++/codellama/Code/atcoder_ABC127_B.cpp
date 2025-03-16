#include <iostream>
using namespace std;

int main()
{
    // Read input values for r, D, and x from the user
    int r, D, x;
    cin >> r >> D >> x;

    // Iterate over a range of values from 2 to 11 (inclusive)
    for (int i = 2; i <= 11; i++)
    {
        // Calculate and print the result based on the formula
        // The formula computes a value using the current iteration index i,
        // the input values r, D, and x, and prints the integer result
        cout << (int)((r ** (i - 1)) * (x + D / (1 - r)) - D / (1 - r)) << endl;
    }

    return 0;
}

