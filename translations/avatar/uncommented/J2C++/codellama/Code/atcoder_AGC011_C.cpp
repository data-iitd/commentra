
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

class Main {
public:
    vector<int> *graph;
    bool *visited;
    int *color;
    long one;
    long bipartite;
    long count;
    bool mujun;
    int dfs(int a, int c) {
        if (visited[a]) {
            if (color[a] >= 0 && color[a] != c) mujun = true;
            return 0;
        }
        visited[a] = true;
        color[a] = c;
        int total = 1;
        for (int b : graph[a]) {
            total += dfs(b, 1 - c);
        }
        return total;
    }
    void run() {
        int n, m;
        scanf("%d%d", &n, &m);
        graph = new vector<int>[n];
        for (int i = 0; i < n; ++i) {
            graph[i] = vector<int>();
        }
        for (int i = 0; i < m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        visited = new bool[n];
        color = new int[n];
        memset(color, -1, sizeof(int) * n);
        one = 0;
        bipartite = 0;
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            count++;
            mujun = false;
            int kind = dfs(i, 0);
            if (kind == 1) one++;
            else if (!mujun) bipartite++;
        }
        long total = one * (2 * n - one);
        total += (count - one) * (count - one);
        total += bipartite * bipartite;
        printf("%ld\n", total);
    }
};

int main() {
    Main m;
    m.run();
    return 0;
}

