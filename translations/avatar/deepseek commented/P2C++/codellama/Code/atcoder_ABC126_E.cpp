#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int INF = 1000000000;
int N, M;
int edge[1000][1000];
bool used[1000];
int ans;
void bfs(int start) {
    queue<int> q;
    q.push(start);
    used[start] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (edge[node][i] && !used[i]) {
                used[i] = true;
                q.push(i);
            }
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        edge[x - 1][y - 1] = edge[y - 1][x - 1] = 1;
    }
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            ans++;
            bfs(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
