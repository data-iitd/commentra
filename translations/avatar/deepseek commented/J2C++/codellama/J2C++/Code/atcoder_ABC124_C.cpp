#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cassert>

using namespace std;

int main() {
    // Read the input string
    string x;
    cin >> x;
    // Create two StringBuilder objects to manipulate the string
    string a = x;
    string b = x;
    // Initialize counters for the number of changes needed
    int a1 = 0;
    int a2 = 0;

    // First loop to change characters to make the string colorful
    for (int i = 1; i < x.length(); i++) {
        if (a[i] == a[i - 1]) {
            // Change the character to the opposite
            if (a[i] == '1') {
                a[i] = '0';
            } else {
                a[i] = '1';
            }
            // Increment the counter
            a1++;
        }
    }

    // Second loop to change characters to make the string colorful
    for (int i = x.length() - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            // Change the character to the opposite
            if (b[i - 1] == '1') {
                b[i - 1] = '0';
            } else {
                b[i - 1] = '1';
            }
            // Increment the counter
            a2++;
        }
    }

    // Output the minimum number of changes needed
    cout << min(a1, a2) << endl;
    return 0;
}

