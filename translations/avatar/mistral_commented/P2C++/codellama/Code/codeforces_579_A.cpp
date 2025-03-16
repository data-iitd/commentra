#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Take an integer input from the user and assign it to the variable n
    int n;
    cin >> n;

    // Initialize a counter variable x to 1
    int x = 1;

    // While loop starts
    while (true)
    {
        // Check if the log base 2 of n is an integer yet
        if (log2(n) == (int)log2(n))
        {
            break;
        }

        // Increment the counter variable x by 1
        x += 1;

        // Update the value of n by subtracting 2 raised to the power of the current log base 2 of n
        n -= pow(2, (int)log2(n));
    }

    // Print the output value of x
    cout << x << endl;

    return 0;
}

