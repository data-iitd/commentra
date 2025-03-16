#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    // Take an integer input from the user
    cin >> n;

    // Take a string input from the user
    cin >> s;

    // Check if n is odd
    if (n % 2 != 0) {
        // Print 'No' if n is odd
        cout << "No" << endl;
    } else {
        // If n is even, compare the first half of the string with the second half
        if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
            // Print 'Yes' if the first half is equal to the second half
            cout << "Yes" << endl;
        } else {
            // Print 'No' if the first half is not equal to the second half
            cout << "No" << endl;
        }
    }

    return 0;
}

