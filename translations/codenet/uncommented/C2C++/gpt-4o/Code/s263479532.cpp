#include <iostream>
#include <vector>
#include <limits>

#define MAX 100
#define INF 999999
#define NIL -1
#define WHITE 0
#define BLACK 2

int prim(int n, const std::vector<std::vector<int>>& G);

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> G(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> G[i][j];
        }
    }

    std::cout << prim(n, G) << std::endl;

    return 0;
}

int prim(int n, const std::vector<std::vector<int>>& G) {
    int u, mincost, sum = 0;
    std::vector<int> d(n, INF);
    std::vector<int> pi(n, NIL);
    std::vector<int> color(n, WHITE);

    d[0] = 0;
    while (true) {
        mincost = INF;

        for (int i = 0; i < n; i++) {
            if (color[i] != BLACK && d[i] < mincost) {
                mincost = d[i];
                u = i;
            }
        }

        if (mincost == INF) break;

        color[u] = BLACK;

        for (int v = 0; v < n; v++) {
            if (color[v] != BLACK && G[u][v] < d[v] && G[u][v] != -1) {
                pi[v] = u;
                d[v] = G[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (d[i] != INF) sum += d[i];
    }

    return sum;
}

// <END-OF-CODE>
