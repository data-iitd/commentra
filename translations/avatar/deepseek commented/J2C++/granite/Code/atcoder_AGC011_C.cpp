
#include <bits/stdc++.h>
using namespace std;

class Main : public thread {
    vector < int > *graph;
    bool *visited;
    int *color;
    long long one, bipartite, count;
    bool mujun;

    int dfs(int a, int c) {
        if (visited[a]) {
            if (color[a] >= 0 && color[a]!= c) mujun = true;
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

public:
    void run() {
        int n, m;
        cin >> n >> m;
        graph = new vector < int > [n];
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            graph[u - 1].push_back(v - 1);
            graph[v - 1].push_back(u - 1);
        }
        visited = new bool[n];
        color = new int[n];
        fill(color, color + n, -1);
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
        long long total = one * (2 * n - one);
        total += (count - one) * (count - one);
        total += bipartite * bipartite;
        cout << total << endl;
    }
};

int main() {
    Main *main = new Main();
    main->start();
    main->join();
    return 0;
}

