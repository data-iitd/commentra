#include <iostream>
using namespace std;

int main() {
    int n, i;
    
    // Read an integer n from the standard input
    cin >> n;
    
    // Iterate from 1 to n (inclusive)
    for (i = 1; i <= n; i++) {
        int a = i;
        
        // Check if the current number i is divisible by 3
        if (a % 3 == 0) {
            cout << " " << i;
        } else {
            // Check each digit of i to see if it contains the digit 3
            for (; a; ) {
                if (a % 10 == 3) {
                    cout << " " << i;
                    a = 0;
                }
                a /= 10;
            }
        }
    }
    
    // Print a newline character
    cout << endl;
    
    return 0;
}
