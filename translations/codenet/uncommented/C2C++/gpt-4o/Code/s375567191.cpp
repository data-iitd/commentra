#include <iostream>
#include <vector>
#define MAX 101
#define WHITE 0
#define BLACK 2
#define GRAY 1

using namespace std;

int time, n;
int g[MAX][MAX] = {0};
int d[MAX], f[MAX], color[MAX] = {WHITE};

void visit(int u) {
    color[u] = GRAY;
    d[u] = ++time;

    for (int i = 0; i < n; i++) {
        if (g[u][i] == 0)
            continue;
        if (color[i] == WHITE)
            visit(i);
    }

    color[u] = BLACK;
    f[u] = ++time;
}

void dfs() {
    time = 0;

    for (int i = 0; i < n; i++)
        if (color[i] == WHITE)
            visit(i);

    for (int i = 0; i < n; i++)
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
}

int main() {
    int x, y, z;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 0; j < y; j++) {
            cin >> z;
            g[x - 1][z - 1] = 1;
        }
    }

    dfs();
    return 0;
}

// <END-OF-CODE>
