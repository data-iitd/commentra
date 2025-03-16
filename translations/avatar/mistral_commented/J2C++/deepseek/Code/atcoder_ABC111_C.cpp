#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(100010);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> vo(100010, 0);
    vector<int> ve(100010, 0);
    vector<int> vt(100010, 0);

    for (int i = 0; i < n; i += 2) {
        vo[v[i]]++;
    }

    for (int i = 1; i < n; i += 2) {
        ve[v[i]]++;
    }

    vector<pair<int, int>> vo_pairs(100010);
    vector<pair<int, int>> ve_pairs(100010);
    vector<pair<int, int>> vt_pairs(100010);

    for (int i = 0; i < 100010; i++) {
        vo_pairs[i] = {vo[i], i};
        ve_pairs[i] = {ve[i], i};
        vt_pairs[i] = {vt[i], i};
    }

    sort(vo_pairs.begin(), vo_pairs.end(), greater<pair<int, int>>());
    sort(ve_pairs.begin(), ve_pairs.end(), greater<pair<int, int>>());
    sort(vt_pairs.begin(), vt_pairs.end(), greater<pair<int, int>>());

    int ans = 0;

    if (vo_pairs[0].second == ve_pairs[0].second) {
        ans = min(n - vo_pairs[0].first - vo_pairs[1].first, n - ve_pairs[0].first - ve_pairs[1].first);
    } else {
        ans = n - vo_pairs[0].first - ve_pairs[0].first;
    }

    cout << ans << endl;

    return 0;
}
