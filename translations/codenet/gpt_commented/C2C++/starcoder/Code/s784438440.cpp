#include <iostream>

using namespace std;

int main() {
    // Declare two integer variables a and b
    int a, b;

    // Read two integers from user input
    cin >> a >> b;

    // Calculate and print the result of the expression
    // The expression computes the number of complete groups of (a-1) that can fit into (b-1) + (a-2)
    cout << ((b - 1) + (a - 2)) / (a - 1) << endl;

    // Return 0 to indicate successful execution of the program
    return 0;
}
