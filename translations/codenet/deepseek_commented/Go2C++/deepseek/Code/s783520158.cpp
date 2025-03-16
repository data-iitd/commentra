#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;
    
    // Read three integer values from the standard input and assign them to a, b, and c
    cin >> a >> b >> c;
    
    // Check if the difference between b and a is equal to the difference between c and b
    if (b - a == c - b) {
        // If the condition is true, print "YES"
        cout << "YES" << endl;
    } else {
        // Otherwise, print "NO"
        cout << "NO" << endl;
    }
    
    return 0;
}

