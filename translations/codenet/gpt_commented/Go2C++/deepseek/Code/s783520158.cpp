#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;
    
    // Read three integers from standard input
    cin >> a >> b >> c;

    // Check if the difference between the first two numbers is equal to the difference between the last two numbers
    if (b - a == c - b) {
        // If the differences are equal, print "YES"
        cout << "YES" << endl;
    } else {
        // If the differences are not equal, print "NO"
        cout << "NO" << endl;
    }

    return 0;
}
