#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

class Fast {
public:
    void sol(istream& is, ostream& os) {
        string s;
        is >> s;
        vector<int> cum(s.size() + 1, 0);
        for (size_t i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                cum[i] = cum[i - 1] + 1;
            } else {
                cum[i] = cum[i - 1];
            }
        }
        int q;
        is >> q;
        while (q--) {
            int l, r;
            is >> l >> r;
            os << (cum[r - 1] - cum[l - 1]) << endl;
        }
    }
};

int main() {
    Fast f;
    f.sol(cin, cout);
    return 0;
}

