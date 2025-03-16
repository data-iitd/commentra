#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant size for the buffered reader
#define SIZE 1000000

// Declare global variables for union-find structure
int *par, *rank;

// Function to read the next line from standard input
char* NextLine() {
    char *line = malloc(SIZE);
    if (fgets(line, SIZE, stdin) == NULL) {
        free(line);
<<<<<<< HEAD
        return NULL; // Handle end of input or error
=======
        return NULL; // Handle any read errors
>>>>>>> 98c87cb78a (data updated)
    }
    return line;
}

// Function to read two integers from the next line of input
void NextInts(int *x, int *y) {
    char *line = NextLine();
<<<<<<< HEAD
    sscanf(line, "%d %d", x, y);
=======
    sscanf(line, "%d %d", x, y); // Read two integers from the line
>>>>>>> 98c87cb78a (data updated)
    free(line);
}

// Function to read an array of integers from the next line of input
int* NextIntArray(int *size) {
    char *line = NextLine();
    int *a = malloc(SIZE * sizeof(int));
    char *token;
    *size = 0;

    token = strtok(line, " ");
    while (token != NULL) {
<<<<<<< HEAD
        a[(*size)++] = atoi(token) - 1; // Decrement for zero-based indexing
=======
        a[(*size)++] = atoi(token); // Convert string to integer
>>>>>>> 98c87cb78a (data updated)
        token = strtok(NULL, " ");
    }
    free(line);
    return a; // Return the integer array
}

// Function to initialize the union-find structure
void initialize(int n) {
<<<<<<< HEAD
    par = malloc(n * sizeof(int));
    rank = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        par[i] = i; // Set each element's parent to itself
=======
    par = malloc(n * sizeof(int)); // Create parent array
    rank = malloc(n * sizeof(int)); // Create rank array

    // Set each element's parent to itself
    for (int i = 0; i < n; i++) {
        par[i] = i;
>>>>>>> 98c87cb78a (data updated)
        rank[i] = 0; // Initialize rank to 0
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
<<<<<<< HEAD
    
    if (i == j) {
        return; // If they are already in the same set, do nothing
    }
    
=======

    if (i == j) {
        return; // If they are already in the same set, do nothing
    }

>>>>>>> 98c87cb78a (data updated)
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

int main() {
    int n, m;
    NextInts(&n, &m); // Read the number of elements (n) and number of unions (m)
<<<<<<< HEAD
    
    int size;
    int *p = NextIntArray(&size); // Read the array of integers
    int x, y;
    
    // Initialize the union-find structure
    initialize(n);
    
=======
    int *p = NextIntArray(&n); // Read the array of integers
    int x, y;

    // Initialize the union-find structure
    initialize(n);

>>>>>>> 98c87cb78a (data updated)
    // Process each union operation
    for (int i = 0; i < m; i++) {
        NextInts(&x, &y); // Read the pair of integers for union
        unite(x - 1, y - 1); // Unite the two elements (convert to zero-based index)
    }
<<<<<<< HEAD
    
    // Count the number of elements that are in the same set as their corresponding value in p
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i])) { // Check if the element is in the same set
            s++; // Increment the count
        }
    }
    
    // Print the result
    printf("%d\n", s);
    
=======

    // Count the number of elements that are in the same set as their corresponding value in p
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i] - 1)) { // Check if the element is in the same set
            s++; // Increment the count
        }
    }

    // Print the result
    printf("%d\n", s);

>>>>>>> 98c87cb78a (data updated)
    // Free allocated memory
    free(par);
    free(rank);
    free(p);
<<<<<<< HEAD
    
=======

>>>>>>> 98c87cb78a (data updated)
    return 0;
}

// <END-OF-CODE>
