#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

class Fast {
public:
    void sol(istream& is, ostream& os) {
        string s;
        getline(is, s);

        // Initialize the cumulative array to store counts of consecutive identical characters
        vector<int> cum(s.length() + 1, 0);

        // Fill the cumulative array with counts of consecutive identical characters
        for (size_t i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                cum[i] = cum[i - 1] + 1;
            else
                cum[i] = cum[i - 1];
        }

        // Read the number of queries
        int q;
        is >> q;

        // Process each query
        for (int i = 0; i < q; i++) {
            int l, r;
            is >> l >> r;

            // Calculate and print the result for the query
            os << (cum[r - 1] - cum[l - 1]) << endl;
        }
    }
};

int main() {
    Fast f;
    f.sol(cin, cout);
    return 0;
}

