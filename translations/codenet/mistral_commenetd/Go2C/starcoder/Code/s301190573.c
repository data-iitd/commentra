
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_N 1000000

// Initialize reader
FILE *reader;

// Function to read a single line from the standard input
char *NextLine() {
  char *buffer = NULL;
  size_t len = 0;
  ssize_t read;
  if (getline(&buffer, &len, reader) == -1) {
    free(buffer);
    return NULL;
  }
  return buffer;
}

// Function to read two integers from a single line
void NextInts(int *x, int *y) {
  char *line = NextLine();
  char *token = strtok(line, " ");
  *x = atoi(token);
  *y = atoi(token);
  free(line);
}

// Function to read an array of integers from a single line
int *NextIntArray() {
  char *line = NextLine();
  char *token = strtok(line, " ");
  int n = 0;
  int *a = malloc(sizeof(int) * MAX_N);
  while (token!= NULL) {
    a[n++] = atoi(token);
    token = strtok(NULL, " ");
  }
  free(line);
  return a;
}

// Initialize arrays for parent and rank
int par[MAX_N], rank[MAX_N];

// Function to initialize arrays
void initialize(int n) {
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rank[i] = 0;
  }
}

// Main function
int main() {
  // Read number of nodes and edges
  int n, m;
  NextInts(&n, &m);
  // Read array of edges
  int *p = NextIntArray();
  // Initialize arrays
  initialize(n);
  // Process each edge by uniting their parents
  for (int i = 0; i < m; i++) {
    int x, y;
    NextInts(&x, &y);
    unite(x-1, y-1);
  }
  // Count the number of disconnected components
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i])) {
      s++;
    }
  }
  // Print the result
  printf("%d\n", s);
}

// Function to find the root of a node
int root(int i) {
  // If the node is its own parent, return it
  if (par[i] == i) {
    return i;
  }
  // Recursively find the root of the parent
  par[i] = root(par[i]);
  // Return the new root
  return par[i];
}

// Function to check if two nodes have the same parent
bool same(int i, int j) {
  // Find the root of both nodes
  return root(i) == root(j);
}

// Function to unite two nodes
void unite(int i, int j) {
  // Find the roots of both nodes
  i = root(i);
  j = root(j);
  // If they already have the same parent, return
  if (i == j) {
    return;
  }
  // Make the smaller rank node a child of the larger rank node
  if (rank[i] < rank[j]) {
    par[i] = j;
  } else {
    par[j] = i;
    // If they have the same rank, increase the rank of the node with the smaller index
    if (rank[i] == rank[j]) {
      rank[i]++;
    }
  }
}

