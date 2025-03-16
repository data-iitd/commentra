
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <utility>
#include <limits>
#include <cassert>
#include <numeric>

using namespace std;

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    a = max(a, b);
    b = min(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

// Main function to solve the problem
int main() {
    string s;  // Read input string
    cin >> s;
    
    string t = "";  // Initialize an empty string to store processed characters
    int i = 0;  // Initialize index
    
    // Process the input string character by character
    while (i < s.length()) {
        if (s[i] == 'A') {
            t += 'A';
            i++;
        } else if (s[i] == 'B') {
            if (i < s.length() - 1) {
                if (s[i + 1] == 'C') {
                    t += 'D';
                    i += 2;
                } else {
                    t += 'X';
                    i++;
                }
            } else {
                t += 'X';
                i++;
            }
        } else {
            t += 'X';
            i++;
        }
    }
    
    int total = 0;  // Initialize total count
    int numA = 0;  // Initialize count of 'A' characters
    
    // Count the number of 'A' characters before each 'X' in the processed string
    for (int i = 0; i < t.length(); i++) {
        if (t[i] == 'X') {
            numA = 0;
        } else {
            if (t[i] == 'A') {
                numA++;
            } else {
                total += numA;
            }
        }
    }
    
    cout << total << endl;  // Print the total count
    
    return 0;
}

// Check if the script is being run as the main module
int main() {
    solve();
    return 0;
}

