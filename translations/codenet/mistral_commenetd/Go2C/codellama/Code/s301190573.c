
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000

// Initialize reader
char buffer[size];
char *line = buffer;
char *nextLine() {
  line = fgets(buffer, size, stdin);
  return line;
}

// Function to read two integers from a single line
int nextInts() {
  int x, y;
  char *s = strtok(line, " ");
  x = atoi(s);
  s = strtok(NULL, " ");
  y = atoi(s);
  return x, y;
}

// Function to read an array of integers from a single line
int *nextIntArray() {
  char *s = strtok(line, " ");
  int *a = malloc(sizeof(int) * strlen(s));
  int i = 0;
  while (s != NULL) {
    a[i] = atoi(s);
    i++;
    s = strtok(NULL, " ");
  }
  return a;
}

// Function to initialize arrays
void initialize(int n) {
  int *par = malloc(sizeof(int) * n);
  int *rank = malloc(sizeof(int) * n);
  // Set all elements as their own parent initially
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

// Main function
int main() {
  // Read number of nodes and edges
  int n, m;
  scanf("%d %d", &n, &m);
  // Read array of edges
  int *p = nextIntArray();
  // Initialize arrays
  initialize(n);
  // Process each edge by uniting their parents
  for (int i = 0; i < m; i++) {
    int x, y;
    x = p[i * 2];
    y = p[i * 2 + 1];
    unite(x - 1, y - 1);
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
  return 0;
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
int same(int i, int j) {
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

