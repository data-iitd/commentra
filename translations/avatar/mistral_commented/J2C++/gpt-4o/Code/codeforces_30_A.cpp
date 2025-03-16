#include <iostream> // Including the iostream library for input and output
#include <cmath> // Including the cmath library for mathematical functions

using namespace std; // Using the standard namespace

class Main { // Main class definition
public:
    void solve() { // solve method definition
        int A, B, n; // Declare variables A, B, and n
        cin >> A >> B >> n; // Reading the integer values from standard input

        if (A == 0) { // Checking if A is equal to zero
            if (B == 0) { // Checking if B is also equal to zero
                cout << 1 << endl; // If both A and B are zero, print 1
            } else {
                cout << "No solution" << endl; // If A is zero but B is not, print "No solution"
                return; // Exit the method
            }
            return; // Exit the method
        }

        if (B % A != 0) { // Checking if B is not divisible by A
            cout << "No solution" << endl; // If B is not divisible by A, print "No solution"
            return; // Exit the method
        }

        B /= A; // Dividing B by A
        bool neg = B < 0; // Checking if B is negative

        if (neg && n % 2 == 0) { // Checking if n is even and B is negative
            cout << "No solution" << endl; // If both conditions are true, print "No solution"
            return; // Exit the method
        }

        if (neg) B = -B; // If B is negative, make it positive

        for (int x = 0; x <= B; x++) { // Iterating through all possible values of x from 0 to B
            if (pow(x, n) == B) { // Checking if x raised to the power of n is equal to B
                cout << (neg ? -x : x) << endl; // Printing the value of x with its sign
                return; // Exit the method
            }
        }

        cout << "No solution" << endl; // If no solution is found, print "No solution"
    }
};

int main() { // Main function definition
    Main m; // Creating an instance of the Main class
    m.solve(); // Calling the solve method
    return 0; // Return 0 to indicate successful execution
}

// <END-OF-CODE>
