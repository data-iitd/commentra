#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant size for the buffered reader
const int size = 1000000;

// Create a buffered reader with the specified size
FILE *reader = fopen("input.txt", "r");

// Function to read the next line from standard input
char *NextLine() {
  char *line = (char *)malloc(size * sizeof(char));
  char *buffer = (char *)malloc(size * sizeof(char));
  int isPrefix = 1;
  int err;
  
  // Read lines until a complete line is received
  while (isPrefix) {
    fgets(line, size, reader);
    strcat(buffer, line);
    isPrefix = strchr(line, '\n') == NULL;
  }
  
  // Return the complete line as a string
  return buffer;
}

// Function to read two integers from the next line of input
int *NextInts() {
  char *line = NextLine();
  char *s = strtok(line, " ");
  int x = atoi(s);
  s = strtok(NULL, " ");
  int y = atoi(s);
  return (int[]){x, y};
}

// Function to read an array of integers from the next line of input
int *NextIntArray() {
  char *line = NextLine();
  char *s = strtok(line, " ");
  int n = 0;
  while (s != NULL) {
    n++;
    s = strtok(NULL, " ");
  }
  int *a = (int *)malloc(n * sizeof(int));
  s = strtok(line, " ");
  for (int i = 0; i < n; i++) {
    a[i] = atoi(s);
    s = strtok(NULL, " ");
  }
  return a;
}

// Declare global variables for union-find structure
int *par, *rank;

int main() {
  // Read the number of elements (n) and number of unions (m)
  int n, m = *NextInts();
  // Read the array of integers
  int *p = NextIntArray();
  int x, y;
  
  // Initialize the union-find structure
  initialize(n);
  
  // Process each union operation
  for (int i = 0; i < m; i++) {
    x, y = *NextInts(); // Read the pair of integers for union
    unite(x-1, y-1);   // Unite the two elements (convert to zero-based index)
  }
  
  // Count the number of elements that are in the same set as their corresponding value in p
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i])) { // Check if the element is in the same set
      s++; // Increment the count
    }
  }
  
  // Print the result
  printf("%d\n", s);
}

// Function to initialize the union-find structure
void initialize(int n) {
  par = (int *)malloc(n * sizeof(int)); // Create parent array
  rank = (int *)malloc(n * sizeof(int)); // Create rank array
  
  // Set each element's parent to itself
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
}

// Function to find the root of the element with path compression
int root(int i) {
  if (par[i] == i) {
    return i; // Return the root if it is its own parent
  }
  par[i] = root(par[i]); // Path compression
  return par[i]; // Return the root
}

// Function to check if two elements are in the same set
int same(int i, int j) {
  return root(i) == root(j); // Check if their roots are the same
}

// Function to unite two elements into the same set
void unite(int i, int j) {
  i = root(i); // Find the root of the first element
  j = root(j); // Find the root of the second element
  
  if (i == j) {
    return; // If they are already in the same set, do nothing
  }
  
  // Union by rank
  if (rank[i] < rank[j]) {
    par[i] = j; // Make j the parent of i
  } else {
    par[j] = i; // Make i the parent of j
    if (rank[i] == rank[j]) {
      rank[i]++; // Increment rank if they were the same
    }
  }
}

