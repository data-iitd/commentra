#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Read input and split into two strings, a and b
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    // Determine the maximum length of the two strings
    int x = max(a.length(), b.length());

    // Pad the shorter string with zeros on the left
    a.insert(0, x - a.length(), '0');

    // Pad the shorter string with zeros on the right
    b.append(x - b.length(), '0');

    // Initialize an empty string to store the result
    string s;

    // Initialize carry to 0
    int c = 0;

    // Loop through each digit from right to left
    for (int i = 0; i < x; i++) {
        // Add the corresponding digits from a and b along with the carry
        int d = (b[i] - '0') + (a[x - i - 1] - '0') + c;

        // If the sum is greater than 9, set carry to 1 and append the tens digit
        if (d > 9) {
            s += to_string(d)[1];
            c = 1;
        } else {
            // Otherwise, append the sum and set carry to 0
            s += to_string(d);
            c = 0;
        }
    }

    // If there's a carry left after the final addition, append '1'
    if (c == 1) {
        s += '1';
    }

    // Reverse the result string and print it as an integer
    reverse(s.begin(), s.end());
    cout << stoi(s) << endl;

    return 0;
}

// <END-OF-CODE>
