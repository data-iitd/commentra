
#include < stdio.h >
#include < stdbool.h >
#include < string.h >
#include < math.h >
#include < time.h >
#include < assert.h >
#include < stdarg.h >
#include < limits.h >
#include < sys/time.h >
#include < algorithm >

typedef long long Int;
typedef unsigned uint;

int N, M;
int* graph;
int* visited;
int* color;
Int one;
Int bipartite;
Int count;
bool mujun;

int dfs(int a, int c) {
   if (visited[a]) {
      if (color[a] >= 0 && color[a]!= c) mujun = true;
      return 0;
   }
   visited[a] = true;
   color[a] = c;
   int total = 1;
   for (int i = graph[a]; i!= 0; i = graph[i]) {
      total += dfs(i, 1 - c);
   }
   return total;
}

void run() {
   scanf("%d%d", &N, &M);
   graph = (int*) malloc(sizeof(int) * (N + 1));
   memset(graph, 0, sizeof(int) * (N + 1));
   for (int i = 0; i < M; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      graph[u] = v;
      graph[v] = u;
   }
   visited = (int*) malloc(sizeof(int) * (N + 1));
   memset(visited, 0, sizeof(int) * (N + 1));
   color = (int*) malloc(sizeof(int) * (N + 1));
   memset(color, -1, sizeof(int) * (N + 1));
   one = 0;
   bipartite = 0;
   count = 0;
   for (int i = 1; i <= N; i++) {
      if (visited[i]) continue;
      count++;
      mujun = false;
      int kind = dfs(i, 0);
      if (kind == 1) one++;
      else if (!mujun) bipartite++;
   }
   Int total = one * (2 * N - one);
   total += (count - one) * (count - one);
   total += bipartite * bipartite;
   printf("%lld\n", total);
}

int main(int argc, char** argv) {
   run();
   return 0;
}

