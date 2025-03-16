#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables to hold the input values
    int a, b, c;
    
    // Read three integers from standard input
    cin >> a >> b >> c;
    
    // Check if the integers are in strictly increasing order
    if (a < b && b < c) {
        // If they are in increasing order, print "Yes"
        cout << "Yes" << endl;
    } else {
        // If they are not in increasing order, print "No"
        cout << "No" << endl;
    }
    
    // End of the main function
    return 0;
}
