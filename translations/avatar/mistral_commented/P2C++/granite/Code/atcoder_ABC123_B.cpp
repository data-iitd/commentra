
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<int>> menu;
    int m, e;
    char c;

    for (int i = 0; i < 5; i++) {
        cin >> m >> c;
        e = c - '0';
        if (e == 0) {
            e = 10;
        }
        menu.push_back({m, e});
    }

    sort(menu.begin(), menu.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int ans = 0;
    for (int i = 1; i < menu.size(); i++) {
        int num_full_10s = ceil(menu[i][0] / 10.0);
        ans += num_full_10s * 10;
    }

    cout << menu[0][0] + ans << endl;

    return 0;
}
