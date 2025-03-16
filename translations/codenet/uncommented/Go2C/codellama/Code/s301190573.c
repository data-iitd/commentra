#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 1000000
char buffer[size];
char *p = buffer;
char *next_line() {
  char *line = p;
  while (*p != '\n' && *p != '\0') { p++; }
  if (*p == '\0') { return NULL; }
  *p = '\0';
  p++;
  return line;
}
int next_ints() {
  int x,y;
  char *line = next_line();
  if (line == NULL) { return 0; }
  sscanf(line,"%d %d",&x,&y);
  return x;
}
int *next_int_array() {
  char *line = next_line();
  if (line == NULL) { return NULL; }
  int *a = (int *)malloc(sizeof(int) * 1000000);
  int i = 0;
  char *p = line;
  while (*p != '\0') {
    sscanf(p,"%d",&a[i]);
    p = strchr(p,' ');
    if (p == NULL) { break; }
    p++;
    i++;
  }
  return a;
}
int *par,*rank;
void initialize(int n) {
  par = (int *)malloc(sizeof(int) * n);
  rank = (int *)malloc(sizeof(int) * n);
  for (int i=0;i<n;i++) {
    par[i] = i;
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

int main() {
  int n,m;
  int *p;
  scanf("%d %d",&n,&m);
  p = next_int_array();
  initialize(n);
  for (int i=0;i<m;i++) {
    int x,y;
    x = next_ints();
    y = next_ints();
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i=0;i<n;i++) {
    if (same(i,p[i])) { s++; }
  }
  printf("%d\n",s);
  return 0;
}
