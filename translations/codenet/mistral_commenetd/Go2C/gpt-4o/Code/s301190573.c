#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000000

// Initialize arrays for parent and rank
int *par, *rank;

// Function to initialize arrays
void initialize(int n) {
    par = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    // Set all elements as their own parent initially
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
}

// Function to read a single line from the standard input
char *nextLine() {
    char *line = (char *)malloc(SIZE);
    fgets(line, SIZE, stdin);
    return line;
}

// Function to read two integers from a single line
void nextInts(int *x, int *y) {
    char *line = nextLine();
    sscanf(line, "%d %d", x, y);
    free(line);
}

// Function to read an array of integers from a single line
int *nextIntArray(int *size) {
    char *line = nextLine();
    int *a = (int *)malloc(SIZE * sizeof(int));
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        a[i++] = atoi(token);
        token = strtok(NULL, " ");
    }
    free(line);
    *size = i; // Set the size of the array
    return a;
}

// Function to find the root of a node
int root(int i) {
    if (par[i] == i) {
        return i;
    }
    par[i] = root(par[i]); // Path compression
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
    nextInts(&n, &m);
    int size;
    int *p = nextIntArray(&size);
    initialize(n);
    
    for (int i = 0; i < m; i++) {
        int x, y;
        nextInts(&x, &y);
        unite(x - 1, y - 1);
    }
    
    // Count the number of disconnected components
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (same(i, p[i] - 1)) {
            s++;
        }
    }
    
    // Print the result
    printf("%d\n", s);
    
    // Free allocated memory
    free(par);
    free(rank);
    free(p);
    
    return 0;
}

// <END-OF-CODE>
