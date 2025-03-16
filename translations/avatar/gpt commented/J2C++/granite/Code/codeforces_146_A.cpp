
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    // Creating a Scanner object to read input from the user
    string str;
    int n;
    cin >> n >> str;
    
    // Variable to check if there are any digits other than '4' or '7'
    int t = 0;
    
    // Checking if all characters in the string are either '4' or '7'
    for (int i = 0; i < n; i++) {
        if (str[i]!= '4' && str[i]!= '7') {
            t = 1; // Set t to 1 if a character is found that is not '4' or '7'
        }
    }
    
    // If t is set, print "NO" indicating the number is not lucky
    if (t == 1) {
        cout << "NO" << endl;
    } else {
        // Calculate the sum of the first half of the digits
        int x = 0;
        for (int i = 0; i < n / 2; i++) {
            x = x + (int)str[i] - 48;
        }
        // Calculate the sum of the second half of the digits
        int y = 0;
        for (int i = n - 1; i > (n / 2) - 1; i--) {
            y = y + (int)str[i] - 48;
        }
        // Compare the two sums and print "YES" if they are equal, otherwise print "NO"
        if (x == y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
