#include <bits/stdc++.h>
using namespace std;

class Fast {
public:
    void sol(istream& cin, ostream& cout) {
        // Read the input string
        string s;
        cin >> s;
        
        // Initialize the cumulative array to store counts of consecutive identical characters
        int cum[s.length() + 1];
        cum[0] = cum[s.length()] = 0;
        
        // Fill the cumulative array with counts of consecutive identical characters
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1])
                cum[i] = cum[i - 1] + 1;
            else
                cum[i] = cum[i - 1];
        }
        
        // Read the number of queries
        int q;
        cin >> q;
        
        // Process each query
        while (q--) {
            // Read the query range
            int l, r;
            cin >> l >> r;
            
            // Calculate and print the result for the query
            cout << cum[r] - cum[l - 1] << endl;
        }
    }
};

int main() {
    Fast f;
    f.sol(cin, cout);
    return 0;
}

