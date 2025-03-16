
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> balls(n, {1, 0});
    balls[0] = {0, 1};

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        int w_x = balls[x].first;
        int r_x = balls[x].second;
        int w_y = balls[y].first;
        int r_y = balls[y].second;

        if (w_x >= 1 && r_x >= 1) {
            balls[x].first--;
            balls[y].second++;
        } else if (w_x == 0) {
            balls[x].second--;
            balls[y].second++;
        } else {
            balls[x].first--;
            balls[y].first++;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (balls[i].second > 0) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
