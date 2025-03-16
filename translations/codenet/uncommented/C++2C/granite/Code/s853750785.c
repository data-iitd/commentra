
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int H[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &H[i]);
    }
    int G[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            G[i][j] = 0;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    int ans = 0;
    for (int u = 0; u < N; u++) {
        bool flag = true;
        for (int v = 0; v < N; v++) {
            if (G[u][v] == 1 && H[u] <= H[v]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
