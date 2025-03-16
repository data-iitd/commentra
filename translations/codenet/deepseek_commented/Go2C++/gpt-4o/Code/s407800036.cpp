#include <iostream>
using namespace std;

int main() {
    // Code for A - Between Two Integers
    int A, B, C;
    cin >> A >> B >> C;

    // Check if C is between A and B (inclusive)
    if (C >= A && C <= B) {
        // If C is between A and B, print "Yes"
        cout << "Yes" << endl;
    } else {
        // If C is not between A and B, print "No"
        cout << "No" << endl;
    }

    return 0;
}

// <END-OF-CODE>
