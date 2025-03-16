
#include <bits/stdc++.h>
using namespace std;

class Main {
public:
int count;
bool seen[100005];
int path = 0, cycle = 1;
vector<vector<int>> graph;

int dfs(int child, int par) {
if (seen[child] == true) return cycle;
seen[child] = true;
for (int i : graph[child]) {
if (i!= par) {
this->count++;
if (dfs(i, child) == cycle) return cycle;
}
}
return path;
}

public:
static void main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int m, n;
cin >> m >> n;
Main ft;
ft.graph.resize(m + 1);
for (int i = 0; i <= m; i++) {
ft.graph[i].clear();
}
ft.seen = new bool[m + 1]();
for (int i = 0; i < n; i++) {
int x, y;
cin >> x >> y;
ft.graph[x].push_back(y);
ft.graph[y].push_back(x);
}
int toremove = 0;
for (int i = 1; i <= m; i++) {
if (!ft.seen[i]) {
ft.count = 0;
if (ft.dfs(i, 0) == ft.cycle) {
if (ft.count % 2 == 1) toremove++;
}
}
}
if ((m - toremove) % 2 == 1) toremove++;
cout << toremove << endl;
}
};

int main() {
Main::main();
return 0;
}

