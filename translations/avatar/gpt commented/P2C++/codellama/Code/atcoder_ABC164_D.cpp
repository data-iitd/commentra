#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Read input string and set the length variable
    string s;
    int l = 2019;
    cin >> s;

    // Initialize a list to count occurrences of remainders, and variables for accumulated value and result
    int m[l], a = 0, r = 0;
    for (int i = 0; i < l; i++) {
        m[i] = 0;
    }

    // Iterate over the input string in reverse order
    for (int i = s.length() - 1; i >= 0; i--) {
        // Update the accumulated value 'a' by converting the character to an integer and adjusting its place value
        a += (s[i] - '0') * pow(10, i, l);

        // Update the result 'r' by adding the count of occurrences of the current remainder
        r += m[a % l];

        // Increment the count of the current remainder in the list 'm'
        m[a % l]++;
    }

    // Print the final result
    cout << r << endl;

    return 0;
}

