#include <iostream>
using namespace std;

int main() {
    // Declare three integer variables a, b, and c
    int a, b, c;
    
    // Read input values for a, b, and c from the user
    cin >> a >> b >> c;

    // Check if c is within the range [a, b]
    if (c >= a && c <= b) {
        // If c is within the range, print "Yes"
        cout << "Yes" << endl;
    } else {
        // If c is outside the range, print "No"
        cout << "No" << endl;
    }

    return 0;
}
