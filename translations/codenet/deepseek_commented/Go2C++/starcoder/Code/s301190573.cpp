#include <bits/stdc++.h>

using namespace std;

const int size = 1000000;
char buffer[size];
int par[size],rank[size];

int root(int i) {
  if (par[i] == i) { return i; }
  par[i] = root(par[i]);
  return par[i];
}

bool same(int i,int j) {
  return root(i) == root(j);
}

void initialize(int n) {
  for (int i=0;i<n;i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

void unite(int i,int j) {
  i = root(i);
  j = root(j);
  if (i == j) { return; }
  if (rank[i] < rank[j]) {
    par[i] = j;
  } else {
    par[j] = i;
    if (rank[i] == rank[j]) { rank[i]++; }
  }
}

int main() {
  int n,m;
  cin >> n >> m;
  int p[n];
  for (int i=0;i<n;i++) {
    cin >> p[i];
    p[i]--;
  }
  initialize(n);
  for (int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  cout << s << endl;
}
// The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

