

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size 1000000

// Initialize reader
char buffer[size];
int index = 0;

// Function to read a single line from the standard input
char* readLine() {
  char* line = (char*)malloc(size * sizeof(char));
  char c;
  int i = 0;
  while ((c = getchar())!= '\n') {
    line[i++] = c;
  }
  line[i] = '\0';
  return line;
}

// Function to read two integers from a single line
int* readInts() {
  char* line = readLine();
  char* token = strtok(line, " ");
  int* ints = (int*)malloc(2 * sizeof(int));
  ints[0] = atoi(token);
  token = strtok(NULL, " ");
  ints[1] = atoi(token);
  free(line);
  return ints;
}

// Function to read an array of integers from a single line
int* readIntArray() {
  char* line = readLine();
  char* token = strtok(line, " ");
  int* array = (int*)malloc(size * sizeof(int));
  int i = 0;
  while (token!= NULL) {
    array[i++] = atoi(token) - 1; // Decrease each index by 1 for some reason
    token = strtok(NULL, " ");
  }
  free(line);
  return array;
}

// Initialize arrays for parent and rank
int* par;
int* rank;

// Function to initialize arrays
void initialize(int n) {
  par = (int*)malloc(n * sizeof(int));
  rank = (int*)malloc(n * sizeof(int));
  // Set all elements as their own parent initially
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

// Main function
int main() {
  // Read number of nodes and edges
  int n, m;
  int* p;
  int* ints = readInts();
  n = ints[0];
  m = ints[1];
  p = readIntArray();
  // Initialize arrays
  initialize(n);
  // Process each edge by uniting their parents
  for (int i = 0; i < m; i++) {
    int* ints = readInts();
    int x = ints[0] - 1;
    int y = ints[1] - 1;
    unite(x, y);
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

// End of code
