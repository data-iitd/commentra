#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int mod = 1000000007;

int main() {
    string s;
    cin >> s;
    int pp = 0;
    int na = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
        int cc = na + (s[i] - '0');
        na = 0;

        if (cc <= 4) {
            pp += cc;
        } else {
            na = 1;
            if (i == 0) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }

    cout << pp << endl;
    return 0;
}

