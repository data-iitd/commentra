#include <stdio.h>
#include <stdlib.h>

<<<<<<< HEAD
// Structure to represent a Binary Indexed Tree (Fenwick Tree)
=======
// Structure to represent a Binary Indexed Tree (Fenwick Tree).
>>>>>>> 98c87cb78a (data updated)
typedef struct {
    int n;      // Number of elements in the tree
    int *data;  // Array to store the tree data
} BIT;

<<<<<<< HEAD
// Function to initialize a new Binary Indexed Tree with n elements
=======
// Function to initialize a new Binary Indexed Tree with n elements.
>>>>>>> 98c87cb78a (data updated)
BIT* FenwickTree(int n) {
    BIT *ret = (BIT *)malloc(sizeof(BIT));
    ret->n = n;
    ret->data = (int *)calloc(n, sizeof(int)); // Create a slice to hold the tree data
    return ret;
}

<<<<<<< HEAD
// Function to update the Fenwick Tree by adding x to the element at position p
=======
// Function to update the Fenwick Tree by adding x to the element at position p.
>>>>>>> 98c87cb78a (data updated)
void Add(BIT *b, int p, int x) {
    p++; // Increment p to match the 1-based index used in Fenwick Tree
    while (p <= b->n) {
        b->data[p - 1] += x; // Update the tree data
        p += p & -p;         // Move to the next index
    }
}

<<<<<<< HEAD
// Function to calculate the sum of elements in the range [l, r)
=======
// Function to calculate the sum of elements in the range [l, r).
>>>>>>> 98c87cb78a (data updated)
int Sum(BIT *b, int l, int r) {
    return sum(b, r) - sum(b, l); // Return the difference of sums
}

<<<<<<< HEAD
// Function to calculate the prefix sum from the start to index r
=======
// Function to calculate the prefix sum from the start to index r.
>>>>>>> 98c87cb78a (data updated)
int sum(BIT *b, int r) {
    int s = 0; // Initialize sum
    while (r > 0) {
        s += b->data[r - 1]; // Add the value at index r-1
<<<<<<< HEAD
        r -= r & -r;         // Move to the parent index
=======
        r -= r & -r;          // Move to the parent index
>>>>>>> 98c87cb78a (data updated)
    }
    return s; // Return the calculated sum
}

<<<<<<< HEAD
// Utility function to read an integer from input
=======
// Utility function to read an integer from input.
>>>>>>> 98c87cb78a (data updated)
int getInt() {
    int x;
    scanf("%d", &x);
    return x;
}

<<<<<<< HEAD
// Utility function to print output to the console
=======
// Utility function to print output to the console.
>>>>>>> 98c87cb78a (data updated)
void out(int x) {
    printf("%d\n", x);
}

int main() {
<<<<<<< HEAD
    // Read the number of elements (n) and the number of queries (q)
    int n = getInt(), q = getInt();

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements
    BIT *fw = FenwickTree(n);

    // Read n integers and add them to the Fenwick Tree
=======
    // Read the number of elements (n) and the number of queries (q).
    int n = getInt(), q = getInt();

    // Initialize a Fenwick Tree (Binary Indexed Tree) with n elements.
    BIT *fw = FenwickTree(n);

    // Read n integers and add them to the Fenwick Tree.
>>>>>>> 98c87cb78a (data updated)
    for (int i = 0; i < n; i++) {
        int a = getInt();
        Add(fw, i, a);
    }

<<<<<<< HEAD
    // Process q queries
    for (int i = 0; i < q; i++) {
        int t = getInt(); // Read the type of query
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree
            int p = getInt(), x = getInt();
            Add(fw, p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r
=======
    // Process q queries.
    for (int i = 0; i < q; i++) {
        int t = getInt(); // Read the type of query.
        if (t == 0) {
            // For update queries, read position (p) and value (x) and update the Fenwick Tree.
            int p = getInt(), x = getInt();
            Add(fw, p, x);
        } else {
            // For sum queries, read the range (l, r) and output the sum from l to r.
>>>>>>> 98c87cb78a (data updated)
            int l = getInt(), r = getInt();
            out(Sum(fw, l, r));
        }
    }

    // Free allocated memory
    free(fw->data);
    free(fw);

    return 0;
}

// <END-OF-CODE>
