
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<vector<int>> patterns = DuplicatePatterns(vector<int>{0, 1, 2, 3}, k);

    for (auto P : patterns) {
        int r = a, g = b, b = c;
        for (int i = 0; i < P.size(); i++) {
            if (P[i] == 0) {
                continue;
            } else if (P[i] == 1) {
                r *= 2;
            } else if (P[i] == 2) {
                g *= 2;
            } else if (P[i] == 3) {
                b *= 2;
            }
        }

        if (g > r && b > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}

vector<vector<int>> DuplicatePatterns(vector<int> elems, int k) {
    if (k == 0) {
        return vector<vector<int>>{vector<int>{}};
    }

    vector<vector<int>> res;
    for (int e : elems) {
        vector<vector<int>> tmp = DuplicatePatterns(elems, k - 1);
        for (auto p : tmp) {
            p.push_back(e);
            res.push_back(p);
        }
    }

    return res;
}

