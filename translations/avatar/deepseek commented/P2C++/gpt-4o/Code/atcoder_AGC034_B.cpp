#include <iostream>
#include <string>
using namespace std;

// Function to compute the greatest common divisor (GCD) of two numbers using the Euclidean algorithm
int gcd(int a, int b) {
    a = max(a, b);
    b = min(a, b);
    while (a % b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return b;
}

// Main function to solve the problem
void solve() {
    string s;
    cin >> s;  // Read input string
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
    int numA = 0;   // Initialize count of 'A' characters
    
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
    
    // Define constants for infinity and modulo
    const long long INF = 10LL * 25;
    const long long mod = 7 + 10LL * 9;
}

// Check if the script is being run as the main module
int main() {
    solve();
    return 0;
}

// <END-OF-CODE>
