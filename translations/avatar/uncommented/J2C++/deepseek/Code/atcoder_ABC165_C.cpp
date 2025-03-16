#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a, b, c, d;
int n, m, q;
long long ans = -100;

void dfs(vector<int>& list) {
    if (list.size() == n) {
        long long score = 0;
        for (int i = 0; i < q; ++i) {
            if (list[b[i]] - list[a[i]] == c[i]) {
                score += d[i];
            }
        }
        ans = max(ans, score);
        return;
    }
    if (!list.empty()) {
        for (int num = list.back(); num <= m; ++num) {
            list.push_back(num);
            dfs(list);
            list.pop_back();
        }
    } else {
        for (int num = 1; num <= m; ++num) {
            list.push_back(num);
            dfs(list);
            list.pop_back();
        }
    }
}

int main() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    for (int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
    }
    vector<int> list;
    dfs(list);
    cout << ans << endl;
    return 0;
}

