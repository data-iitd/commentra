#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000

int main() {
  int n,m,x,y,i,j,s,p[size],par[size],rank[size];
  scanf("%d%d",&n,&m);
  for (i=0;i<n;i++) {
    scanf("%d",&p[i]);
    p[i]--;
  }
  initialize(n);
  for (i=0;i<m;i++) {
    scanf("%d%d",&x,&y);
    x--;
    y--;
    unite(x,y);
  }
  s = 0;
  for (i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  printf("%d\n",s);
}

void initialize(int n) {
  int i;
  for (i=0;i<n;i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

int root(int i) {
  if (par[i] == i) { return i; }
  par[i] = root(par[i]);
  return par[i];
}

int same(int i,int j) {
  return root(i) == root(j);
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

