#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b; // Read two integers a and b

    if (a > 0) {
        // Check if a is greater than 0
        cout << "Positive" << endl;
    } else if (a <= 0 && b >= 0) {
        // Check if a is less than or equal to 0 and b is greater than or equal to 0
        cout << "Zero" << endl;
    } else {
        // If neither of the above conditions is met
        if ((a + b) % 2 == 0) {
            // Check if the sum of a and b is even
            cout << "Negative" << endl;
        } else {
            cout << "Positive" << endl; // If odd, print 'Positive'
        }
    }

    return 0;
}
// <END-OF-CODE>
