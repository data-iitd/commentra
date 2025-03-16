
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set<int> left;
    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        left.insert(i);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r, win;
        cin >> l >> r >> win;
        l--;
        r--;
        win--;
        while (left.upper_bound(l) != left.end() && *left.upper_bound(l) <= r) {
            int curr = *left.upper_bound(l);
            answer[curr] = win;
            left.erase(curr);
        }
        answer[win] = 0;
        left.insert(win);
    }
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += to_string(answer[i]) + " ";
    }
    cout << ans << endl;
    return 0;
}

