#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Fast {
public:
    void sol(istream &in, ostream &out) {
        // Read the first line of input to get the string
        string s;
        in >> s;

        // Initialize a cumulative array to count consecutive characters
        vector<int> cum(s.length() + 1, 0);

        // Fill the cumulative array with counts of consecutive characters
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                cum[i] = cum[i - 1] + 1; // Increment count if the current character is the same as the previous
            else
                cum[i] = cum[i - 1]; // Carry forward the previous count if different
        }

        // Read the number of queries from the input
        int q;
        in >> q;

        // Process each query
        while (q-- > 0) {
            // Read the range for the query
            int l, r;
            in >> l >> r;
            r--; // Adjust r to be zero-based

            // Calculate and print the result for the current query
            out << cum[r] - cum[l - 1] << endl;
        }
    }
};

int main() {
    // Create an instance of the Fast class to process the input
    Fast f;

    // Call the solution method to handle the input and produce output
    f.sol(cin, cout);

    return 0;
}

// <END-OF-CODE>
