

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Main {
public:
 int count;
 bool* seen;
 int path = 0, cycle = 1;
 vector<vector<int>> graph;

 int dfs(int child, int par) {
 if (seen[child] == true) {
 return cycle;
 }
 seen[child] = true;

 for (int i : graph[child]) {
 if (i!= par) {
 this.count++;
 if (dfs(i, child) == cycle) {
 return cycle;
 }
 }
 }
 return path;
 }

 int main() {
 int m, n;
 cin >> m >> n;
 graph = vector<vector<int>>(m + 1);
 seen = new bool[m + 1];

 for (int i = 0; i <= m; i++) {
 graph[i] = vector<int>();
 }

 for (int i = 0; i < n; i++) {
 int x, y;
 cin >> x >> y;
 graph[x].push_back(y);
 graph[y].push_back(x);
 }

 int toremove = 0;
 for (int i = 1; i <= m; i++) {
 if (!seen[i]) {
 count = 0;
 if (dfs(i, 0) == cycle) {
 if (count % 2 == 1) {
 toremove++;
 }
 }
 }
 }

 if ((m - toremove) % 2 == 1) {
 toremove++;
 }

 cout << toremove << endl;

 return 0;
 }
}

