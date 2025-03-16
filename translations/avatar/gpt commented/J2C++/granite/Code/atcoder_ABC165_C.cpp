
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, q;
vector<int> a, b, c, d;
long long ans = -100000000000000000LL;

void dfs(vector<int>& list, int idx) {
    if (idx == n) {
        long long score = 0;
        for (int i = 0; i < q; i++) {
            if (list[b[i]] - list[a[i]] == c[i]) {
                score += d[i];
            }
        }
        ans = max(ans, score);
        return;
    }
    for (int i = idx == 0? 1 : list[idx - 1]; i <= m; i++) {
        list.push_back(i);
        dfs(list, idx + 1);
        list.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--;
        b[i]--;
    }
    vector<int> list;
    dfs(list, 0);
    cout << ans << endl;
    return 0;
}

