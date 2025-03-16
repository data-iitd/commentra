#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
const int INF = 1000000000;
int N, M;
int edge[1000][1000];
bool used[1000];
int ans;
void bfs(int start) {
    memset(used, false, sizeof(used));
    deque<int> queue;
    queue.push_back(start);
    while (!queue.empty()) {
        int node = queue.front();
        queue.pop_front();
        if (used[node]) continue;
        used[node] = true;
        ans++;
        for (int i = 0; i < edge[node].size(); i++) {
            int nextnode = edge[node][i];
            if (!used[nextnode]) queue.push_back(nextnode);
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        edge[X - 1].push_back(Y - 1);
        edge[Y - 1].push_back(X - 1);
    }
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            bfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
