#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> lst(N);
    for (int i = 0; i < N; i++) {
        cin >> lst[i];
    }
    vector<int> lst_p, lst_m;
    for (int i = 0; i < N; i++) {
        if (lst[i] == 0) {
            K--;
        }
        if (lst[i] > 0) {
            lst_p.push_back(lst[i]);
        } else if (lst[i] < 0) {
            lst_m.push_back(lst[i]);
        }
    }
    int p = 0, m = 0, x = 0, y = lst_m.size() - 1, lastx = lst_p.size(), lasty = lst_m.size();
    auto check = [&](int k) {
        int ans = 1000000000;
        for (int j = 0; j <= k; j++) {
            if (j > lastx || k - j > lasty) {
                continue;
            }
            if (j == 0) {
                p = 0;
            } else {
                p = lst_p[j - 1];
            }
            if (k - j == 0) {
                m = 0;
            } else {
                m = lst_m[lasty - (k - j)];
            }
            ans = min(ans, 2 * p + abs(m), p + 2 * abs(m));
        }
        return ans;
    };
    cout << check(K) << endl;
    return 0;
}

