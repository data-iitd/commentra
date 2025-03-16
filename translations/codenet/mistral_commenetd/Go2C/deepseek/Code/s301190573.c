#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

char buffer[SIZE];
int par[SIZE], rank[SIZE];

// Function to read a single line from the standard input
char* NextLine() {
  fgets(buffer, SIZE, stdin);
  return buffer;
}

// Function to read two integers from a single line
void NextInts(int* x, int* y) {
  char* s = strtok(NextLine(), " ");
  *x = atoi(s);
  s = strtok(NULL, " ");
  *y = atoi(s);
}

// Function to read an array of integers from a single line
int* NextIntArray(int* n) {
  char* s = strtok(NextLine(), " ");
  *n = 0;
  int* a = (int*)malloc(sizeof(int));
  while (s != NULL) {
    a[*n] = atoi(s);
    (*n)++;
    a = (int*)realloc(a, (*n + 1) * sizeof(int));
    s = strtok(NULL, " ");
  }
  return a;
}

// Function to initialize arrays
void initialize(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

// Function to find the root of a node
int root(int i) {
  if (par[i] == i) {
    return i;
  }
  par[i] = root(par[i]);
  return par[i];
}

// Function to check if two nodes have the same parent
int same(int i, int j) {
  return root(i) == root(j);
}

// Function to unite two nodes
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

// Main function
int main() {
  int n, m;
  NextInts(&n, &m);
  int* p = NextIntArray(&n);
  initialize(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    NextInts(&x, &y);
    unite(x - 1, y - 1);
  }
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i] - 1)) {
      s++;
    }
  }
  printf("%d\n", s);
  free(p);
  return 0;
}

