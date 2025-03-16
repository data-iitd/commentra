
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant size for the buffered reader
#define SIZE 1000000

// Create a buffered reader with the specified size
char buffer[SIZE];

// Function to read the next line from standard input
char* readline() {
  int ch;
  char* buf = buffer;
  int len = 0;
  
  // Read characters until a newline is encountered
  while ((ch = getchar())!= '\n') {
    *buf++ = ch;
    len++;
  }
  
  // Null-terminate the string and return it
  *buf = '\0';
  return buffer;
}

// Function to read two integers from the next line of input
int readint() {
  int x;
  scanf("%d", &x);
  return x;
}

// Function to read an array of integers from the next line of input
int* readintarray() {
  char* line = readline();
  char* token = strtok(line, " ");
  int n = 0;
  int* a = (int*)malloc(sizeof(int) * 100000);
  
  // Convert each token to an integer and store in the array
  while (token!= NULL) {
    a[n++] = atoi(token);
    token = strtok(NULL, " ");
  }
  
  return a;
}

// Declare global variables for union-find structure
int par[100000];
int rank[100000];

int main() {
  // Read the number of elements (n) and number of unions (m)
  int n = readint();
  int m = readint();
  int* p = readintarray();
  int x, y;
  
  // Initialize the union-find structure
  for (int i = 0; i < n; i++) {
    par[i] = i;
  }
  
  // Process each union operation
  for (int i = 0; i < m; i++) {
    x = readint() - 1; // Read the pair of integers for union
    y = readint() - 1; // Convert to zero-based index
    unite(x, y);       // Unite the two elements
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
  
  return 0;
}

// Function to initialize the union-find structure
void initialize(int n) {
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

// End of code
