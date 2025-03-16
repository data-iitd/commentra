

#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    vector<vector<int>> patterns;
    function<void(vector<int>, int)> generatePatterns = [&](vector<int> pattern, int remaining) {
        if (remaining == 0) {
            patterns.push_back(pattern);
            return;
        }
        for (int i = 0; i < 4; i++) {
            vector<int> newPattern = pattern;
            newPattern.push_back(i);
            generatePatterns(newPattern, remaining - 1);
        }
    };

    generatePatterns({}, k);

    for (auto pattern : patterns) {
        int r = a, g = b, bl = c;
        for (int i : pattern) {
            if (i == 0) continue;
            if (i == 1) r *= 2;
            if (i == 2) g *= 2;
            if (i == 3) bl *= 2;
        }
        if (g > r && bl > g) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}

