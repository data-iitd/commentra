#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

const int MOD = 1000000000 + 7;

void duplicatePatterns(vector<int>& elems, int k, vector<vector<int>>& res, vector<int>& pattern) {
    if (pattern.size() == k) {
        res.push_back(pattern);
        return;
    }

    for (int e : elems) {
        pattern.push_back(e);
        duplicatePatterns(elems, k, res, pattern);
        pattern.pop_back();
    }
}

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<int> elems = {0, 1, 2, 3};
    vector<vector<int>> patterns;
    vector<int> pattern;

    duplicatePatterns(elems, k, patterns, pattern);

    for (const auto& P : patterns) {
        int r = a, g = b, b_ = c; // Renaming b to b_ to avoid conflict with the variable name

        for (int i : P) {
            if (i == 0) {
                continue;
            } else if (i == 1) {
                r *= 2;
            } else if (i == 2) {
                g *= 2;
            } else if (i == 3) {
                b_ *= 2;
            }
        }

        if (g > r && b_ > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

/* <END-OF-CODE> */
