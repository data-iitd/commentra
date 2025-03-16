#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MOD 1000000007
#define INF INT_MAX

void main() {
    int n, m, R;
    scanf("%d %d %d", &n, &m, &R);

    int rs[R];
    for (int i = 0; i < R; i++) {
        scanf("%d", &rs[i]);
        rs[i]--;
    }

    int costs[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            costs[i][j] = INF;
        }
        costs[i][i] = 0;
    }

    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        a--;
        b--;
        costs[a][b] = c;
        costs[b][a] = c;
    }

    // ワーシャルフロイド法で最短経路を算出
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (costs[i][k] != INF && costs[k][j] != INF && costs[i][k] + costs[k][j] < costs[i][j]) {
                    costs[i][j] = costs[i][k] + costs[k][j];
                }
            }
        }
    }

    // 順列で訪問先の順序をすべて試す
    // これでは重複して訪問する町がでてしまうか。。
    // ここでは順列生成の部分を省略し、直接計算することにします。
    int ans = INF;
    for (int i = 0; i < R; i++) {
        for (int j = i+1; j < R; j++) {
            for (int k = j+1; k < R; k++) {
                int tmp = costs[rs[i]][rs[j]] + costs[rs[j]][rs[k]] + costs[rs[k]][rs[i]];
                if (tmp < ans) {
                    ans = tmp;
                }
            }
        }
    }
    printf("%d\n", ans);
}

