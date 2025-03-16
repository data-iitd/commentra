#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            li[i].push_back(y);
        }
    }
    
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    
    set<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < li[i].size(); j++) {
            q.insert(li[i][j]);
        }
    }
    
    set<int> r;
    for (int i = 1; i <= n; i++) {
        r.insert(i);
    }
    
    set<int> v = r - q;
    
    int ans = 0;
    for (int i = 0; i <= q.size(); i++) {
        for (auto s : itertools::combinations(q, i)) {
            for (int j = 0; j < m; j++) {
                if (p[j]!= (s & set<int>(li[j])).size() % 2) {
                    break;
                }
            } else {
                ans += 1 << v.size();
            }
        }
    }
    
    cout << ans << "\n";
}

