#include <iostream>
#include <vector>

#define N 200
#define SHIRO 0
#define HAI 1
#define KURO 2

void aaaaa();
void bbbbb(int);

int n, A[N][N];
int color[N], d[N], f[N];
int TT;

int main() {
    int u, k, v;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cin >> u >> k;
        u--;
        for (int j = 0; j < k; j++) {
            std::cin >> v;
            v--;
            A[u][v] = 1;
        }
    }

    aaaaa();

    return 0;
}

void aaaaa() {
    for (int i = 0; i < n; i++) {
        color[i] = SHIRO;
    }

    TT = 0;

    for (int u = 0; u < n; u++) {
        if (color[u] == SHIRO) {
            bbbbb(u);
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " " << d[i] << " " << f[i] << std::endl;
    }
}

void bbbbb(int k) {
    color[k] = HAI;
    TT++;
    d[k] = TT;
    for (int v = 0; v < n; v++) {
        if (A[k][v] == 0) continue;
        if (color[v] == SHIRO) {
            bbbbb(v);
        }
    }
    color[k] = KURO;
    f[k] = ++TT;
}

// <END-OF-CODE>
