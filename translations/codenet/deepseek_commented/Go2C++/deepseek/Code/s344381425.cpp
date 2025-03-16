#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables to store input values
    int a, b, c;
    
    // Read three integers from standard input and assign them to a, b, and c
    cin >> a >> b >> c;
    
    // Check if a is less than b and b is less than c
    if (a < b && b < c) {
        // If the condition is true, print "Yes"
        cout << "Yes" << endl;
    } else {
        // Otherwise, print "No"
        cout << "No" << endl;
    }
    
    // Return from the function
    return 0;
}

