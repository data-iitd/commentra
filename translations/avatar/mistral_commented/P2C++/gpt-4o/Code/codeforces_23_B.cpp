#include <iostream>
using namespace std;

int main() {
    // Take an integer input from the user and assign it to the variable n
    int n;
    cin >> n;

    // Iterate n times
    for (int i = 0; i < n; i++) {
        // Take an integer input from the user and assign it to the variable a
        int a;
        cin >> a;

        // Check if a is less than 2
        if (a < 2) {
            // If a is less than 2, print 0
            cout << 0 << endl;

            // Move to the next iteration of the loop
            continue;
        }

        // If a is not less than 2, check if it is greater than or equal to 2
        if (a >= 2) {
            // If a is greater than or equal to 2, print a - 2
            cout << a - 2 << endl;
        }
    }

    return 0;
}
// <END-OF-CODE>
