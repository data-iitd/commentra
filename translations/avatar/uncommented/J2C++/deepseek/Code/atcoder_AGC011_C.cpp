#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

class Main {
public:
    vector<int> graph[100005];
    bool visited[100005];
    int color[100005];
    long long one;
    long long bipartite;
    long long count;
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
        cin >> n >> m;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        memset(visited, false, sizeof(visited));
        memset(color, -1, sizeof(color));
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
    Main main_instance;
    main_instance.run();
    return 0;
}

