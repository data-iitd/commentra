#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <queue>
#include <utility>
#include <climits>
#include <numeric>
#include <functional>

using namespace std;

const int MOD = 1000000007;

void main_b() {
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
            } else {
                pp += 10 - cc;
            }
        }
    }
    cout << pp << endl;
}

int main() {
    string s;
    cin >> s;
    int pmin = 1000;
    int mmin = 0;
    s = '0' + s;
    for (int i = s.length() - 1; i >= 0; --i) {
        int v = s[i] - '0';
        int npmin = min(pmin + 10 - (v + 1), mmin + 10 - v);
        int nmmin = min(pmin + v + 1, mmin + v);
        pmin = npmin;
        mmin = nmmin;
    }
    cout << min(pmin, mmin) << endl;
    return 0;
}
