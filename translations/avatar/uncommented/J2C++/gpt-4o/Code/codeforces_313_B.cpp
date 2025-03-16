#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Fast {
public:
    void sol(istream &in, ostream &out) {
        string s;
        getline(in, s);
        vector<int> cum(s.length() + 1, 0);
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                cum[i] = cum[i - 1] + 1;
            } else {
                cum[i] = cum[i - 1];
            }
        }
        
        int q;
        in >> q;
        in.ignore(); // To ignore the newline after the integer input
        while (q--) {
            int l, r;
            in >> l >> r;
            r--; // Adjusting r to be zero-based
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
