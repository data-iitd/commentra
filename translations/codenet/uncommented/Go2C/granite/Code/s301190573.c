
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000

char buf[size];

char *NextLine() {
  fgets(buf,size,stdin);
  if (buf[strlen(buf)-1] == '\n') { buf[strlen(buf)-1] = '\0'; }
  return buf;
}

int NextInt() {
  int x;
  scanf("%d",&x);
  return x;
}

int *NextIntArray() {
  int n = NextInt();
  int *a = (int *)malloc(sizeof(int)*n);
  int i;
  for (i=0;i<n;i++) {
    a[i] = NextInt();
    a[i]--;
  }
  return a;
}

int *par;
int *rank;

void initialize(int n) {
  int i;
  par = (int *)malloc(sizeof(int)*n);
  rank = (int *)malloc(sizeof(int)*n);
  for (i=0;i<n;i++) {
    par[i] = i;
  }
}

int root(int i) {
  if (par[i] == i) { return i; }
  par[i] = root(par[i]);
  return par[i];
}

int same(int i, int j) {
  return root(i) == root(j);
}

void unite(int i, int j) {
  int x = root(i);
  int y = root(j);
  if (x == y) { return; }
  if (rank[x] < rank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (rank[x] == rank[y]) { rank[x]++; }
  }
}

int main() {
  int n = NextInt();
  int m = NextInt();
  int *p = NextIntArray();
  int i,x,y,s;
  initialize(n);
  for (i=0;i<m;i++) {
    x = NextInt();
    y = NextInt();
    unite(x-1,y-1);
  }
  s = 0;
  for (i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  printf("%d\n",s);
  return 0;
}
