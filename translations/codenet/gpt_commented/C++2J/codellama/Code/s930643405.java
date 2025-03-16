#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <array>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

// Define a pair type for convenience
typedef pair<int,int> P;

// Array to track forbidden digits
boolean d[10] = {false}; // Initialize all digits as not forbidden
int n, k; // Variables to hold the input number and the count of forbidden digits
boolean hantei = true; // Flag to determine if the current number is valid

int main() {
    // Read the initial number 'n' and the count of forbidden digits 'k'
    cin >> n >> k;

    // Read the forbidden digits and mark them in the array
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a; // Input each forbidden digit
        d[a] = true; // Mark the digit as forbidden
    }

    // Infinite loop to find the next valid number
    while (true) {
        int x = n; // Start checking from the current number 'n'
        hantei = true; // Reset the validity flag for the new number

        // Check each digit of the number 'x'
        while (x > 0) {
            // If the current digit is forbidden
            if (d[x % 10]) {
                hantei = false; // Mark the number as invalid
                break; // Exit the digit checking loop
            }
            x /= 10; // Remove the last digit
        }

        // If the number is valid (no forbidden digits found)
        if (hantei) {
            cout << n << endl; // Output the valid number
            break; // Exit the infinite loop
        }
        n++; // Increment the number and check the next one
    }
}

