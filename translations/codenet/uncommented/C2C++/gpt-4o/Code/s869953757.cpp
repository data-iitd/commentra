#include <iostream>
#include <vector>
#include <queue>

#define M 100
#define whi 0
#define gra 1
#define bla 2

int n;
int T[M][M];
int color[M], d[M];

void bfs(int s) {
    for (int i = 0; i < n; i++) {
        color[i] = whi;
        d[i] = 1000000;
    }

    color[s] = gra;
    d[s] = 0;
    std::queue<int> Q;
    Q.push(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (int v = 0; v < n; v++) {
            if (T[u][v] == 1 && color[v] == whi) {
                color[v] = gra;
                d[v] = d[u] + 1;
                Q.push(v);
            }
        }
        color[u] = bla;
    }
}

int main() {
    int u, k, v;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            T[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            v--;
            T[u][v] = 1;
        }
    }

    bfs(0);

    for (int i = 0; i < n; i++) {
        if (d[i] == 1000000) d[i] = -1;
        std::cout << i + 1 << " " << d[i] << std::endl;
    }

    return 0;
}

// <END-OF-CODE>
