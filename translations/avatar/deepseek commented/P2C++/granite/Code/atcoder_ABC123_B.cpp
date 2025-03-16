

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, ans = 0;
    vector<pair<int, int>> menu;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        e = n % 10;
        if (e == 0) e = 10;
        menu.push_back({n, e});
    }
    sort(menu.begin(), menu.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    for (int i = 1; i < menu.size(); i++) {
        ans += (menu[i].first + 9) / 10 * 10;
    }
    ans += menu[0].first;
    cout << ans << endl;
    return 0;
}

