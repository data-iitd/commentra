#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Use faster input
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    // Read input and split into two strings a and b
    cin >> a >> b;

    // Determine the maximum length of the two strings
    int x = max(a.length(), b.length());

    // Right-justify 'a' and left-justify 'b' to ensure both have the same length, padding with '0'
    a.insert(a.begin(), x - a.length(), '0');
    b.append(x - b.length(), '0');

    // Initialize an empty string to store the result and a carry variable
    string s;
    int c = 0;

    // Iterate over each digit from the least significant to the most significant
    for (int i = 0; i < x; i++) {
        // Calculate the sum of the corresponding digits and the carry
        int d = (b[i] - '0') + (a[x - i - 1] - '0') + c;

        // Check if the sum exceeds 9, which requires a carry
        if (d > 9) {
            s += to_string(d)[1];  // Append the last digit of the sum to the result
            c = 1;  // Set carry to 1 for the next iteration
        } else {
            s += to_string(d);  // Append the sum to the result
            c = 0;  // Reset carry to 0
        }
    }

    // If there's a carry left after the last addition, append '1' to the result
    if (c == 1) {
        s += '1';
    }

    // Print the final result, reversing the string to get the correct order
    reverse(s.begin(), s.end());
    cout << stoi(s) << endl;  // Convert to int to remove leading zeros

    return 0;
}

// <END-OF-CODE>
