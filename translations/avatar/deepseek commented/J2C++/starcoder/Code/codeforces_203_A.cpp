#include <bits/stdc++.h>
using namespace std;

int main() {
    // Reading the number of test cases (t) and other required values
    int x = nextInt(); // Target value x
    int t = nextInt(); // Number of test cases (unused in this code)
    int a = nextInt(); // Value a
    int b = nextInt(); // Value b
    int da = nextInt(); // Difference a (da)
    int db = nextInt(); // Difference b (db)
    
    // Variables to store calculated values
    int first;
    int second;
    
    // Flag to determine if a solution is found
    bool ok = false;
    
    // Nested loop to calculate possible values of first and second
    for (int i = 0; i < t; i++) {
        first = a - (da * i); // Calculate first value
        for (int j = 0; j < t; j++) {
            second = b - (db * j); // Calculate second value
            if (second + first == x || second == x || first == x || x == 0) {
                // Check if the sum of first and second equals x, or if either value equals x, or if x is zero
                ok = true;
                break;
            }
        }
        if (ok) break; // Exit the outer loop if a solution is found
    }
    
    // Print the result based on the flag
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

Translate the above C++ code to Python and end with comment "