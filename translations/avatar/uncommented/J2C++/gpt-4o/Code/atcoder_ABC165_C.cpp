#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0, m = 0, q = 0;
long long ans = -100LL;
vector<int> a, b, c, d;

void dfs(vector<int>& list) {
    if (list.size() == n) {
        long long score = 0LL;
        for (int i = 0; i < q; ++i) {
            score += (list[b[i]] - list[a[i]] == c[i]) ? d[i] : 0LL;
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
        a[i]--; // Adjusting for 0-based index
        b[i]--; // Adjusting for 0-based index
    }
    
    vector<int> list;
    dfs(list);
    cout << ans << endl;
    
    return 0;
}

// <END-OF-CODE>
