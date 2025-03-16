#include <stdio.h>
#include <string.h>

typedef long long ll;

int mat[3000][3000];
ll dp[3000][3000][4];
ll dpl[3000];

int main(int argc, char **argv)
{
    int rr, cc, k;

    scanf("%d %d %d", &rr, &cc, &k);
    for (int i = 1; i <= k; i++) {
        int r, c, v;
        scanf("%d %d %d", &r, &c, &v);
        mat[r - 1][c - 1] = v;
    }
    dp[0][0][1] = mat[0][0];
    for (int y = 0; y < rr; y++) {
        for (int x = 0; x < cc; x++) {
            for (int c = 0; c < 4; c++) {
                int v = mat[y][x];
                ll q;
                if (c == 0 || v == 0) {
                    q = (x == 0) ? dpl[x] : (dpl[x] > dp[y][x - 1][c] ? dpl[x] : dp[y][x - 1][c]);
                } else {
<<<<<<< HEAD
                    q = (x == 0) ? dpl[x] + v : (dpl[x] + v > dp[y][x - 1][c] ? (dpl[x] + v > dp[y][x - 1][c - 1] + v ? dpl[x] + v : dp[y][x - 1][c - 1] + v) : (dp[y][x - 1][c]));
=======
                    q = (x == 0) ? dpl[x] + v : (dpl[x] + v > dp[y][x - 1][c] ? dpl[x] + v : (dp[y][x - 1][c] > dp[y][x - 1][c - 1] + v ? dp[y][x - 1][c] : dp[y][x - 1][c - 1] + v));
>>>>>>> 98c87cb78a (data updated)
                }
                dp[y][x][c] = q;
            }
        }
        for (int x = 0; x < cc; x++) {
            dpl[x] = dp[y][x][0];
            if (dp[y][x][1] > dpl[x]) dpl[x] = dp[y][x][1];
            if (dp[y][x][2] > dpl[x]) dpl[x] = dp[y][x][2];
            if (dp[y][x][3] > dpl[x]) dpl[x] = dp[y][x][3];
        }
    }
    printf("%lld\n", dpl[cc - 1]);
    return 0;
}

// <END-OF-CODE>
