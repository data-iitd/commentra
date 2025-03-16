#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Fast {
public:
    void sol(istream &in, ostream &out) {
        // Read the input string
        string s;
        in >> s;

        // Initialize the cumulative array to store counts of consecutive identical characters
        vector<int> cum(s.length() + 1, 0);

        // Fill the cumulative array with counts of consecutive identical characters
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                cum[i] = cum[i - 1] + 1;
            else
                cum[i] = cum[i - 1];
        }

        // Read the number of queries
        int q;
        in >> q;

        // Process each query
        while (q--) {
            int l, r;
            in >> l >> r;
            r--; // Convert to 0-based index

            // Calculate and print the result for the query
            out << cum[r] - cum[l - 1] << endl;
        }
    }
};

int main() {
    Fast f;
    f.sol(cin, cout);
    return 0;
}

// <END-OF-CODE>
