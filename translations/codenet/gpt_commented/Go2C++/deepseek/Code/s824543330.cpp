#include <iostream>
using namespace std;

int main() {
    // Declare two integer variables to hold the input values
    int a, b;
    
    // Read two integers from standard input
    cin >> a >> b;

    // Check if the product of a and b is even or odd
    if (a * b % 2 == 0) {
        // If the product is even, print "Even"
        cout << "Even" << endl;
    } else {
        // If the product is odd, print "Odd"
        cout << "Odd" << endl;
    }

    return 0;
}
