
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_N 500000
#define MAX_Q 500000

int n, q;
int C[MAX_N];

typedef struct {
    int idx, l, r;
} Query;

Query Q[MAX_Q];

int P[MAX_N + 50];
int Answers[MAX_N + 50];

int main() {
    // Read the number of elements and queries
    scanf("%d %d", &n, &q);

    // Read the slice of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    // Initialize the position array with -1 (indicating unvisited)
    for (int i = 1; i <= n; i++) {
        P[i] = -1;
    }

    // Read each query and store it in the Q slice
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        Query query = {idx: i, l: l, r: r};
        Q[i] = query;
    }

    // Sort the queries based on the right bound
    sort(Q, Q + q, [](Query a, Query b) { return a.r < b.r; });

    int k = 0; // Pointer to track the current position in the input array
    // Process each query
    for (int i = 0; i < q; i++) {
        Query query = Q[i];
        // Update the Fenwick Tree for all elements up to the right bound of the current query
        while (k < query.r) {
            if (P[C[k]] != -1) { // If the current value has been seen before
                P[C[k]] = -1; // Remove its previous occurrence from the Fenwick Tree
            }
            P[C[k]] = k; // Update the last position of the current value
            k++; // Move to the next position
        }
        // Calculate the answer for the current query using the Fenwick Tree
        Answers[query.idx] = 0;
        for (int j = query.l; j <= query.r; j++) {
            Answers[query.idx] += P[j];
        }
    }

    // Output the answers for all queries
    for (int i = 0; i < q; i++) {
        printf("%d\n", Answers[i]); // Print each answer
    }

    return 0;
}

