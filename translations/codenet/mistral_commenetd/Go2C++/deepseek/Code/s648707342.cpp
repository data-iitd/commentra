#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arms(n);

    for (int i = 0; i < n; ++i) {
        int x, l;
        cin >> x >> l;
        arms[i] = {x - l, x + l};
    }

    sort(arms.begin(), arms.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int ans = 1;
    int r = arms[0].second;

    for (int i = 1; i < n; ++i) {
        if (arms[i].first >= r) {
            ++ans;
            r = arms[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}

