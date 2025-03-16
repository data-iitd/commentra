#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    // Read an integer input from the user
    cin >> n;

    // Read a string input from the user
    cin >> s;

    // Check if the length of the string is odd
    if (n % 2 != 0) {
        // If the length is odd, print 'No' since it cannot be split into two equal halves
        cout << "No" << endl;
    } else {
        // Check if the first half of the string is equal to the second half
        if (s.substr(0, n / 2) == s.substr(n / 2, n / 2)) {
            // If both halves are equal, print 'Yes'
            cout << "Yes" << endl;
        } else {
            // If the halves are not equal, print 'No'
            cout << "No" << endl;
        }
    }

    return 0;
}

