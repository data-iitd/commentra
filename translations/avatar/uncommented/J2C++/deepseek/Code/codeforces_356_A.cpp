#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
        l--; r--;
        auto it = left.lower_bound(l);
        while (it != left.end() && *it <= r) {
            int curr = *it;
            answer[curr] = win;
            it = left.erase(it);
        }
        answer[win - 1] = 0;
        left.insert(win - 1);
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
