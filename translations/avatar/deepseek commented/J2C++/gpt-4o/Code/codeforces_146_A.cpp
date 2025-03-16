#include <iostream>
#include <string>

using namespace std;

int main() {
    int x = 0, y = 0;
    int t = 0;
    int n;
    cin >> n; // Read the integer n
    string str;
    cin >> str; // Read the string str

    // Check each character in the string
    for (int i = 0; i < n; i++) {
        if (str[i] != '4' && str[i] != '7') {
            t = 1; // Set t to 1 if a character is neither '4' nor '7'
        }
    }

    // If t is 1, print "NO"
    if (t == 1) {
        cout << "NO" << endl;
    } else {
        // Calculate the sum of the first half of the string
        for (int i = 0; i < n / 2; i++) {
            x += str[i] - '0'; // Convert char to int
        }
        // Calculate the sum of the second half of the string
        for (int i = n - 1; i >= n / 2; i--) {
            y += str[i] - '0'; // Convert char to int
        }
        // If x equals y, print "YES", otherwise print "NO"
        if (x == y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

// <END-OF-CODE>
