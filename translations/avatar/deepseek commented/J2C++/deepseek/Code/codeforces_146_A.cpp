#include <iostream>
#include <string>
using namespace std;

int main() {
    int x = 0, y = 0;
    int n;
    string str;
    cin >> n; // Read the integer n
    cin >> str; // Read the string str

    // Check each character in the string
    for (int i = 0; i < n; i++) {
        if (str[i] != '4' && str[i] != '7') {
            cout << "NO" << endl;
            return 0;
        }
    }

    // Calculate the sum of the first half of the string
    for (int i = 0; i < n / 2; i++) {
        x += str[i] - '0';
    }

    // Calculate the sum of the second half of the string
    for (int i = n - 1; i > (n / 2) - 1; i--) {
        y += str[i] - '0';
    }

    // If x equals y, print "YES", otherwise print "NO"
    if (x == y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

