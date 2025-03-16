#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    // Determine the maximum length of the two strings
    int x = max(a.size(), b.size());

    // Pad the shorter string with zeros on the left
    a = string(x - a.size(), '0') + a;

    // Pad the shorter string with zeros on the right
    b = b + string(x - b.size(), '0');

    // Initialize an empty string to store the result
    string s = "";

    // Initialize carry to 0
    int c = 0;

    // Loop through each digit from right to left
    for (int i = 0; i < x; i++) {
        // Add the corresponding digits from a and b along with the carry
        int d = (b[x - i - 1] - '0') + (a[i] - '0') + c;

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
