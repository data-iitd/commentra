#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Define a modulo value
const int mod = 1000000007;

// Main function for base case
void main_b() {
    string s;
    cin >> s;
    long long pp = 0;
    int na = 0;

    // Iterate over the string in reverse order
    for (int i = s.size() - 1; i >= 0; --i) {
        int c = s[i] - '0'; // Convert char to int
        int cc = na + c;
        na = 0;

        // If the sum is less than or equal to 4, add to pp
        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            // If it's the last digit, add 1 to pp
            if (i == s.size() - 1) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }
    // Print the result
    cout << pp << endl;
}

// Main function for general case
long long main_func() {
    string s;
    cin >> s;
    long long pmin = 1000;
    long long mmin = 0;
    s = '0' + s; // Prepend '0' to the string

    // Iterate over the string in reverse order
    for (int i = s.size() - 1; i >= 0; --i) {
        int v = s[i] - '0'; // Convert char to int
        long long npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        long long nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    // Return the minimum of pmin and mmin
    return min(pmin, mmin);
}

int main() {
    // Check if the script is running in test mode
    bool isTest = false;

    // Main execution block
    long long ret = main_func();
    if (ret != -1) {
        cout << ret << endl;
    }

    return 0;
}

// <END-OF-CODE>
