#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000
#define max 1000000

char buffer[size];
int buffer_index = 0;

char* next_line() {
  char* line = buffer + buffer_index;
  int is_prefix = 1;
  int err;
  while (is_prefix) {
    err = getline(&line,&is_prefix,stdin);
    if (err == -1) {
      perror("Error reading from standard input");
      exit(1);
    }
    buffer_index += strlen(line);
  }
  return buffer;
}

int next_int() {
  char* line = next_line();
  char* end;
  int x = strtol(line,&end,10);
  if (end == line) {
    fprintf(stderr,"Error reading integer from standard input\n");
    exit(1);
  }
  return x;
}

int* next_int_array() {
  char* line = next_line();
  char* end;
  int* a = malloc(sizeof(int)*max);
  int i = 0;
  while (line[i] != '\0') {
    a[i] = strtol(line+i,&end,10);
    if (end == line+i) {
      fprintf(stderr,"Error reading integer from standard input\n");
      exit(1);
    }
    i++;
  }
  return a;
}

int* par = malloc(sizeof(int)*max);
int* rank = malloc(sizeof(int)*max);

void initialize(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

int root(int i) {
  if (par[i] == i) {
    return i;
  }
  par[i] = root(par[i]);
  return par[i];
}

int same(int i, int j) {
  return root(i) == root(j);
}

void unite(int i, int j) {
  i = root(i);
  j = root(j);
  if (i == j) {
    return;
  }
  if (rank[i] < rank[j]) {
    par[i] = j;
  } else {
    par[j] = i;
    if (rank[i] == rank[j]) {
      rank[i]++;
    }
  }
}

int main() {
  int n = next_int();
  int m = next_int();
  int* p = next_int_array();
  initialize(n);
  for (int i = 0; i < m; i++) {
    int x = next_int();
    int y = next_int();
    unite(x-1,y-1);
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i,p[i])) {
      s++;
    }
  }
  printf("%d\n",s);
  return 0;
}
// The main function initializes the union-find data structure, processes the union operations, and counts the number of elements in the same connected component as their corresponding values in the array p.


