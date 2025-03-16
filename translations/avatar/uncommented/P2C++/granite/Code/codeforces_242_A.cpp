
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    vector<pair<int, int>> games;
    for (int i = a; i <= x; i++) {
        if (i <= b) continue;
        for (int j = b; j <= y; j++) {
            if (i > j) {
                games.push_back(make_pair(i, j));
            }
        }
    }
    cout << games.size() << endl;
    for (auto game : games) {
        cout << game.first << " " << game.second << endl;
    }
    return 0;
}

