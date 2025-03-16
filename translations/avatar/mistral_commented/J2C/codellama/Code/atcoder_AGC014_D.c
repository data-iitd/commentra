
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declaring static variables
static int **g;
static int maxMatching; // To store the maximum number of edges that can be matched in a bipartite graph

// Function to find the maximum number of edges that can be matched in a bipartite graph
static int maxMatching(int v, int p) {
    int a = 0; // Number of edges matched from the neighboring vertices of 'v'
    int o = 0; // Number of vertices that have odd degree (unmatched vertices) in the neighboring vertices of 'v'

    // Iterating through all the neighbors of 'v'
    for (int i = 0; i < g[v][0]; ++i) {
        int w = g[v][i + 1];
        if (w == p) continue; // Skip if the neighbor is 'p' (self-loop)

        // Recursively calling the function for the neighbor 'w' and updating the values of 'a' and 'o'
        int r = maxMatching(w, v);
        a += r / 2;
        o += r % 2;
    }

    // Returning the result based on the parity of 'o'
    return 2 * a + (o % 2);
}

int main() {
    // Creating an instance of MyScanner class for reading input
    MyScanner sc = new MyScanner();
    FILE *out = fopen("output.txt", "w"); // Creating an instance of PrintWriter for output

    // Reading the number of vertices in the graph
    int n = sc.nextInt();

    // Initializing the graph as an ArrayList of ArrayLists
    g = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        g[i] = (int *)malloc((g[i][0] + 1) * sizeof(int));
    }

    // Reading the edges and adding them to the graph
    for (int i = 0; i < n - 1; ++i) {
        int a = sc.nextInt() - 1; // Reading the first vertex of the edge
        int b = sc.nextInt() - 1; // Reading the second vertex of the edge
        g[a][0]++; // Incrementing the degree of 'a'
        g[a][g[a][0]] = b; // Adding the edge from 'a' to 'b'
        g[b][0]++; // Incrementing the degree of 'b'
        g[b][g[b][0]] = a; // Adding the edge from 'b' to 'a'
    }

    // Finding the maximum number of edges that can be matched in the graph
    maxMatching = maxMatching(0, -1) / 2;

    // Printing the result based on whether all vertices have even degree or not
    fprintf(out, "%s\n", 2 * maxMatching == n ? "Second" : "First");

    // Closing the output stream
    fclose(out);

    // Freeing the memory allocated for the graph
    for (int i = 0; i < n; ++i) {
        free(g[i]);
    }
    free(g);

    return 0;
}

// Structure for MyScanner class
typedef struct MyScanner {
    FILE *br;
    char *st;
} MyScanner;

// Constructor for MyScanner class
MyScanner newMyScanner() {
    MyScanner sc;
    sc.br = fopen("input.txt", "r");
    return sc;
}

// Function to read the next token from the input stream
char *MyScanner_next(MyScanner *sc) {
    while (sc->st == NULL || strlen(sc->st) == 0) {
        sc->st = (char *)malloc(1000 * sizeof(char));
        fgets(sc->st, 1000, sc->br);
    }
    char *token = strtok(sc->st, " ");
    sc->st = NULL;
    return token;
}

// Overloaded functions for reading different data types
int MyScanner_nextInt(MyScanner *sc) {
    return atoi(MyScanner_next(sc));
}

long MyScanner_nextLong(MyScanner *sc) {
    return atol(MyScanner_next(sc));
}

double MyScanner_nextDouble(MyScanner *sc) {
    return atof(MyScanner_next(sc));
}

char *MyScanner_nextLine(MyScanner *sc) {
    char *str = (char *)malloc(1000 * sizeof(char));
    fgets(str, 1000, sc->br);
    return str;
}

