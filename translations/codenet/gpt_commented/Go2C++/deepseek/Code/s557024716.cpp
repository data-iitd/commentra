#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <queue>
#include <tuple>

using namespace std;

#define MOD 1000000007
#define INF_INT 2147483647
#define INF_LONG 9223372036854775807

#define int long long

int a, b, c, k;

vector<vector<int>> duplicatePatterns(const vector<int>& elems, int k) {
    if (k == 0) {
        return {{}};
    }

    vector<vector<int>> res;
    for (int e : elems) {
        vector<int> newPattern = elems;
        newPattern.push_back(e);
        auto subPatterns = duplicatePatterns(newPattern, k - 1);
        res.insert(res.end(), subPatterns.begin(), subPatterns.end());
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b >> c >> k;

    auto patterns = duplicatePatterns({0, 1, 2, 3}, k);

    for (const auto& P : patterns) {
        int r = a, g = b, bl = c;
        for (int i = 0; i < P.size(); ++i) {
            if (P[i] == 1) {
                r *= 2;
            } else if (P[i] == 2) {
                g *= 2;
            } else if (P[i] == 3) {
                bl *= 2;
            }
        }

        if (g > r && bl > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
