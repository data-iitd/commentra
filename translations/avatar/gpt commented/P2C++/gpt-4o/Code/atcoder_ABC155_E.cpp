#include <iostream>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

long long main_b() {
    string s;
    cin >> s;  // Read input string
    long long pp = 0;  // Initialize the total score
    int na = 0;  // Initialize carry-over value

    // Process the string in reverse order
    for (int i = s.size() - 1; i >= 0; --i) {
        int c = s[i] - '0';  // Convert character to integer
        int cc = na + c;  // Calculate the current value with carry-over
        na = 0;  // Reset carry-over for the next iteration

        // Determine how to update the total score based on the current value
        if (cc <= 4) {
            pp += cc;  // If the value is 4 or less, add it directly to the score
        } else {
            na = 1;  // Set carry-over if the value exceeds 4
            if (i == s.size() - 1) {
                pp += 1;  // If it's the last digit, add 1 to the score
            }
            pp += 10 - cc;  // Add the difference to the score
        }
    }

    return pp;  // Output the final score
}

long long main_func() {
    string s;
    cin >> s;  // Read input string
    long long pmin = 1000;  // Initialize minimum score for positive values
    long long mmin = 0;  // Initialize minimum score for negative values
    s = '0' + s;  // Prepend '0' to the input string for easier processing

    // Process the string in reverse order
    for (int i = s.size() - 1; i >= 0; --i) {
        int v = s[i] - '0';  // Convert character to integer
        // Calculate new minimum scores based on current digit
        long long npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        long long nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;  // Update positive minimum score
        mmin = nmmin;  // Update negative minimum score
    }

    return min(pmin, mmin);  // Return the minimum score between positive and negative
}

int main() {
    long long ret = main_func();  // Call the main function
    cout << ret << endl;  // Print the result
    return 0;
}

// <END-OF-CODE>
