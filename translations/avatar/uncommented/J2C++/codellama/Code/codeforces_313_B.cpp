
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
using namespace std;

class Fast {
public:
    void sol(istream &br, ostream &pw) {
        string s;
        getline(br, s);
        vector<int> cum(s.length() + 1, 0);
        cum[0] = cum[s.length()] = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) cum[i] = cum[i - 1] + 1;
            else cum[i] = cum[i - 1];
        }
        int q;
        getline(br, s);
        stringstream ss(s);
        ss >> q;
        while (q--) {
            getline(br, s);
            stringstream ss(s);
            int l, r;
            ss >> l >> r;
            pw << cum[r - 1] - cum[l - 2] << endl;
        }
    }
};

int main() {
    Fast f;
    f.sol(cin, cout);
    return 0;
}

