#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        m[val]++;
    }
    int max = INT_MIN;
    for (auto it = m.begin(); it!= m.end(); it++) {
        int val = it->second;
        max = max > val? max : val;
    }
    cout << max << m.size() << endl;
    return 0;
}
