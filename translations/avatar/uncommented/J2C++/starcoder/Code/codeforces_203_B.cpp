#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    int black[N + 2][N + 2];
    for (int m = 1; m <= M; m++) {
        int x, y;
        cin >> x >> y;
        for (int xx = x - 1; xx <= x + 1; xx++) {
            for (int yy = y - 1; yy <= y + 1; yy++) {
                if (++black[xx][yy] == 9) {
                    cout << m;
                    return 0;
                }
            }
        }
    }
    cout << "-1";
    return 0;
}
