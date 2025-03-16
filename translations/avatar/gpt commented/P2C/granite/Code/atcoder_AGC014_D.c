
#include <stdio.h>
#include <stdlib.h>
#include <queue>

int main() {
    int N;
    scanf("%d", &N);

    std::vector<std::vector<int>> adj(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::queue<int> que;
    que.push(1);

    std::vector<int> seen(N + 1, 0);
    seen[1] = 1;

    std::vector<int> par(N + 1, 0);

    std::vector<int> child_num(N + 1, 0);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int u : adj[v]) {
            if (seen[u] == 0) {
                seen[u] = 1;
                par[u] = v;
                child_num[v] += 1;
                que.push(u);
            }
        }
    }

    std::deque<int> seq;

    for (int i = 1; i <= N; i++) {
        if (child_num[i] == 0) {
            seq.push_back(i);
        }
    }

    while (!seq.empty()) {
        int c = seq.back();
        seq.pop_back();
        seen[c] = 0;
        if (seen[par[c]] == 0) {
            printf("First\n");
            return 0;
        }
        seen[par[c]] = 0;
        child_num[par[par[c]]] -= 1;
        if (child_num[par[par[c]]] == 0) {
            seq.push_back(par[par[c]]);
        }
    }

    printf("Second\n");

    return 0;
}
