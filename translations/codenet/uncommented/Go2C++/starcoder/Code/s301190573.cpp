#include <bits/stdc++.h>
using namespace std;

const int size = 1000000;
char buffer[size];
int par[size],rank[size];

int root(int i) {
  if (par[i] == i) { return i; }
  return par[i] = root(par[i]);
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
  scanf("%d%d",&n,&m);
  int p[n];
  for (int i=0;i<n;i++) {
    scanf("%d",&p[i]);
    p[i]--;
  }
  initialize(n);
  for (int i=0;i<m;i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  printf("%d\n",s);
}
