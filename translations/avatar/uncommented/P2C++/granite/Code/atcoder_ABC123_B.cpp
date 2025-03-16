
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<pair<int, int>> menu;
    for (int i = 0; i < 5; i++) {
        string m;
        cin >> m;
        int e = stoi(m.substr(m.length() - 1));
        if (e == 0) {
            e = 10;
        }
        menu.push_back(make_pair(stoi(m), e));
    }
    sort(menu.begin(), menu.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });
    int ans = 0;
    for (int i = 1; i < menu.size(); i++) {
        ans += (menu[i].first + 9) / 10 * 10;
    }
    ans += menu[0].first;
    cout << ans << endl;
    return 0;
}

