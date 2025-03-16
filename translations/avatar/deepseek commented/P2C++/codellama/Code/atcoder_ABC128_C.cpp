#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> li(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        li[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> li[i][j];
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
    
    set<int> v;
    set_difference(r.begin(), r.end(), q.begin(), q.end(), inserter(v, v.begin()));
    
    int ans = 0;
    for (int i = 0; i <= q.size(); i++) {
        for (auto s : combinations(q, i)) {
            bool flag = true;
            for (int j = 0; j < m; j++) {
                set<int> t(s);
                if (t.size() != s.size()) {
                    continue;
                }
                for (int k = 0; k < li[j].size(); k++) {
                    if (t.find(li[j][k]) == t.end()) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            if (flag) {
                ans += pow(2, v.size());
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

