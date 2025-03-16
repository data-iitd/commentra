#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#define MAX 1000000

int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  int *p = (int *)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++) {
    scanf("%d",&p[i]);
  }
  int *par = (int *)malloc(sizeof(int)*n);
  int *rank = (int *)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++) {
    par[i] = i;
    rank[i] = 0;
  }
  for (int i=0;i<m;i++) {
    int x,y;
    scanf("%d%d",&x,&y);
    x--;
    y--;
    int xroot = root(x,par,rank);
    int yroot = root(y,par,rank);
    if (xroot == yroot) { continue; }
    if (rank[xroot] < rank[yroot]) {
      par[xroot] = yroot;
    } else {
      par[yroot] = xroot;
      if (rank[xroot] == rank[yroot]) { rank[xroot]++; }
    }
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i],par)) { s++; }
  }
  printf("%d\n",s);
}

bool same(int i,int j,int *par) {
  int xroot = root(i,par,rank);
  int yroot = root(j,par,rank);
  return xroot == yroot;
}
int root(int i,int *par,int *rank) {
  if (par[i] == i) { return i; }
  par[i] = root(par[i],par,rank);
  return par[i];
}

