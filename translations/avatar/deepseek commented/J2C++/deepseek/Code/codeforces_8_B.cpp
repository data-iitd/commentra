#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    string s;
    cin >> s;
    int x = 0, y = 0, k = 0;
    vector<int> co[2];
    co[0].push_back(x);
    co[1].push_back(y);

    for (char c : s) {
        switch (c) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
        }
        co[0].push_back(x);
        co[1].push_back(y);
    }

    bool flag = true;
    for (int i = 0; i < co[0].size() - 3; ++i) {
        for (int j = i + 3; j < co[0].size(); ++j) {
            int dx = abs(co[0][i] - co[0][j]);
            int dy = abs(co[1][i] - co[1][j]);
            if ((dx <= 1 && dy == 0) || (dy <= 1 && dx == 0)) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }

    if (flag) cout << "OK" << endl;
    else cout << "BUG" << endl;

    return 0;
}
