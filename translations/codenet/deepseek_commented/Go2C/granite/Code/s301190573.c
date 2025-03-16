
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000

int par[size];
int rank[size];

void initialize(int n) {
  int i;
  for (i = 0; i < n; i++) {
    par[i] = i;
  }
}

int root(int i) {
  if (par[i] == i) {
    return i;
  } else {
    par[i] = root(par[i]);
    return par[i];
  }
}

int same(int i, int j) {
  return root(i) == root(j);
}

void unite(int i, int j) {
  int x = root(i);
  int y = root(j);
  if (x == y) {
    return;
  }
  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y]) {
      rank[x]++;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int p[n];
  int i, x, y;
  initialize(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    p[i]--;
  }
  for (i = 0; i < m; i++) {
    scanf("%d %d", &x, &y);
    x--;
    y--;
    unite(x, y);
  }
  int s = 0;
  for (i = 0; i < n; i++) {
    if (same(i, p[i])) {
      s++;
    }
  }
  printf("%d\n", s);
  return 0;
}
// The above C code translates the given Go code to C. It initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.

