#include <iostream> // Including iostream for input/output
#include <vector>   // Including vector for using dynamic arrays
#include <algorithm> // Including algorithm for using algorithms like sort
#include <cmath>    // Including cmath for mathematical functions
using namespace std;

const int MOD = 1e9 + 7; // Declaring a constant named MOD

int main() { // Main function
    ios::sync_with_stdio(false); // Fast input/output
    cin.tie(nullptr); // Untie cin from cout

    int t; // Declaring an integer variable for the number of test cases
    cin >> t; // Reading the number of test cases

    while (t--) { // Starting a while loop that runs t times
        long long n, a, b; // Declaring long long variables for n, a, and b
        cin >> n >> a >> b; // Reading the values of n, a, and b

        if (n < a) { // Checking if n is less than a
            cout << "No" << endl; // If true, printing "No" and continuing to the next test case
            continue; // Using the continue statement to skip the rest of the current iteration
        }

        if (a == b) { // Checking if a is equal to b
            if (n % a == 0) { // Checking if n is divisible by a
                cout << "Yes" << endl; // If true, printing "Yes"
            } else { // If false
                cout << "No" << endl; // Printing "No"
            }
            continue; // Using the continue statement to skip the rest of the current iteration
        }

        long long x = b / (b - a); // Calculating the value of x
        if (n > x * a) { // Checking if n is greater than x * a
            cout << "Yes" << endl; // If true, printing "Yes" and continuing to the next test case
            continue; // Using the continue statement to skip the rest of the current iteration
        }

        long long low = 1; // Initializing a long long variable named low to 1
        long long high = x + 1; // Initializing a long long variable named high to x + 1
        long long ans = 1; // Initializing a long long variable named ans to 1

        while (low <= high) { // Starting a while loop that runs until low is less than or equal to high
            long long mid = (low + high) / 2; // Calculating the middle value of low and high
            if (mid * a < n) { // Checking if mid * a is less than n
                low = mid + 1; // If true, setting low to mid + 1
            } else { // If false
                ans = mid; // Setting ans to mid
                high = mid - 1; // Setting high to mid - 1
            }
        }

        if (n > (ans - 1) * b && n < ans * a) { // Checking if n is between (ans - 1) * b and ans * a
            cout << "No" << endl; // If true, printing "No"
        } else { // If false
            cout << "Yes" << endl; // Printing "Yes"
        }
    }

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
