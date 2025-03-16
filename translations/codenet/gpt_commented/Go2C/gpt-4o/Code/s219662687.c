#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INF (int)(pow(10, 11))

// Function to compare two integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to calculate the absolute value
int abs(int x) {
    return x < 0 ? -x : x;
}

// Function to find the minimum of two integers
int min(int x, int y) {
    return x < y ? x : y;
}

<<<<<<< HEAD
int main() {
    // Read the number of elements in the first array A
    int A;
    scanf("%d", &A);
    
    // Read the number of elements in the second array B
    int B;
    scanf("%d", &B);
    
    // Read the number of queries Q
    int Q;
    scanf("%d", &Q);
=======
// Function to read the next integer from input
int nextInt() {
    int x;
    scanf("%d", &x);
    return x;
}

int main() {
    // Read the number of elements in the first array A
    int A = nextInt();
    // Read the number of elements in the second array B
    int B = nextInt();
    // Read the number of queries Q
    int Q = nextInt();
>>>>>>> 98c87cb78a (data updated)

    // Initialize the first array with boundary values
    int *s = (int *)malloc((A + 2) * sizeof(int));
    s[0] = -INF;
    s[A + 1] = INF;
<<<<<<< HEAD
    
    // Populate the first array with input values
    for (int i = 1; i <= A; i++) {
        scanf("%d", &s[i]);
=======
    // Populate the first array with input values
    for (int i = 1; i <= A; i++) {
        s[i] = nextInt();
>>>>>>> 98c87cb78a (data updated)
    }

    // Initialize the second array with boundary values
    int *t = (int *)malloc((B + 2) * sizeof(int));
    t[0] = -INF;
    t[B + 1] = INF;
<<<<<<< HEAD
    
    // Populate the second array with input values
    for (int i = 1; i <= B; i++) {
        scanf("%d", &t[i]);
=======
    // Populate the second array with input values
    for (int i = 1; i <= B; i++) {
        t[i] = nextInt();
>>>>>>> 98c87cb78a (data updated)
    }

    // Sort both arrays
    qsort(s, A + 2, sizeof(int), compare);
    qsort(t, B + 2, sizeof(int), compare);

    // Process each query
    for (int i = 0; i < Q; i++) {
        // Read the query value x
<<<<<<< HEAD
        int x;
        scanf("%d", &x);
        
        // Find the position in the first array where x would fit
        int b = 0, d = 0;
        while (b <= A + 1 && s[b] < x) b++;
        while (d <= B + 1 && t[d] < x) d++;

=======
        int x = nextInt();
        
        // Find the position in the first array where x would fit
        int b = (int)(lower_bound(s, s + A + 2, x) - s);
        int d = (int)(lower_bound(t, t + B + 2, x) - t);
        
>>>>>>> 98c87cb78a (data updated)
        // Initialize the result with infinity
        int res = INF;

        // Check the closest values in the first array
        for (int j = b - 1; j <= b; j++) {
            // Check the closest values in the second array
            for (int k = d - 1; k <= d; k++) {
                // Calculate the distances for both possible paths
                int S = s[j];
                int T = t[k];
                int d1 = abs(S - x) + abs(T - S);
                int d2 = abs(T - x) + abs(S - T);
                // Update the result with the minimum distance found
                res = min(res, min(d1, d2));
            }
        }

        // Output the result for the current query
        printf("%d\n", res);
    }

    // Free allocated memory
    free(s);
    free(t);

    return 0;
}

<<<<<<< HEAD
=======
// Function to find the lower bound (similar to sort.SearchInts in Go)
int* lower_bound(int* arr, int* end, int value) {
    while (arr < end) {
        int* mid = arr + (end - arr) / 2;
        if (*mid < value) {
            arr = mid + 1;
        } else {
            end = mid;
        }
    }
    return arr;
}

>>>>>>> 98c87cb78a (data updated)
// <END-OF-CODE>
