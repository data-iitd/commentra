#include <iostream>
using namespace std;

int main() {
    // Read three integers A, B, and C from standard input
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
