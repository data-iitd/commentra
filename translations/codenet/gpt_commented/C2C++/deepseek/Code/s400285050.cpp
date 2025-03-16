#include <iostream>
using namespace std;

// Function prototype declaration for 'you' which takes two integers and returns an integer
int you(int, int);

int main() {
    // Declare variables to hold input values and result
    int x, y, z;

    // Read two integers from user input
    cin >> x >> y;

    // Call the 'you' function with the larger and smaller of the two integers
    if (x >= y) 
        z = you(x, y); // If x is greater than or equal to y, pass x and y to 'you'
    else 
        z = you(y, x); // Otherwise, pass y and x to 'you'

    // Print the result returned from the 'you' function
    cout << z << endl;

    // Return 0 to indicate successful completion of the program
    return 0;
}

// Function 'you' that computes the greatest common divisor (GCD) using the Euclidean algorithm
int you(int x, int y) {
    int z;

    // Infinite loop to perform the Euclidean algorithm
    while (true) {
        z = x % y; // Calculate the remainder of x divided by y
        x = y;     // Update x to be y
        y = z;     // Update y to be the remainder

        // Break the loop if y becomes zero or negative
        if (y <= 0) break;
    }

    // Return the last non-zero value of x, which is the GCD
    return x;
}

