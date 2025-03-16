
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100005];
int maxMatching(int v, int p) {
    int a = 0, o = 0;
    for (int w : g[v]) {
        if (w == p) continue;
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }
    return 2 * a + min(1, o) + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int m = maxMatching(1, 0) / 2;
    cout << (2 * m == n? "Second" : "First") << endl;
    return 0;
}

