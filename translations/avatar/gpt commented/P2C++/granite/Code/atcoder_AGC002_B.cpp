
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> balls(N, vector<int>(2, 0));
    balls[0][0] = 0;
    balls[0][1] = 1;
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        int w_x = balls[x][0];
        int r_x = balls[x][1];
        int w_y = balls[y][0];
        int r_y = balls[y][1];
        if (w_x >= 1 && r_x >= 1) {
            balls[x][0] -= 1;
            balls[y][1] += 1;
        } else if (w_x == 0) {
            balls[x][1] -= 1;
            balls[y][1] += 1;
        } else {
            balls[x][0] -= 1;
            balls[y][0] += 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (balls[i][1]) {
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}

