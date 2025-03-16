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
        li[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> li[i][j];
        }
    }
    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }
    set<int> q;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
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
        vector<int> s(q.begin(), q.begin() + i);
        for (int j = 0; j < m; j++) {
            set<int> t(s);
            for (int k = 1; k < n; k++) {
                if (t.find(li[j][k]) == t.end()) {
                    break;
                }
                t.erase(li[j][k]);
            }
            if (t.size() % 2 != p[j]) {
                break;
            }
        }
        ans += pow(2, v.size());
    }
    cout << ans << endl;
    return 0;
}

