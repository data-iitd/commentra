
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, a, b, sa;
    string s;
    vector<string> ss;

    // Read two integers n and m from input
    cin >> n >> m;

    // Count the number of '-' characters in the input string
    cin >> s;
    sa = count(s.begin(), s.end(), '-');

    // Calculate the minimum of the remaining characters (n - sa) and the count of '-' (sa)
    sa = min(n - sa, sa);

    // Loop m times to read pairs of integers a and b
    while (m--) {
        // Read two integers a and b from input
        cin >> a >> b;

        // Calculate the difference b - a
        b -= a;

        // Check if b is odd and less than or equal to double the count of '-'
        // Append "1\n" to the results if true, otherwise append "0\n"
        ss.push_back((b % 2 and b <= sa << 1)? "1\n" : "0\n");
    }

    // Print the concatenated results from the vector
    for (const auto &s : ss) {
        cout << s;
    }

    return 0;
}
