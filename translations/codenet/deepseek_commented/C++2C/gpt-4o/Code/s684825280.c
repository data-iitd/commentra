#include <stdio.h>
#include <stdlib.h>

#define SIZE ((int)(1e5 * 2) + 13) // Define the size of the count array

int cnt[SIZE]; // Array to count occurrences of each integer

int compare(const void *a, const void *b) {
<<<<<<< HEAD
    return (*(int*)a - *(int*)b; // Comparison function for qsort
=======
    return (*(int *)a - *(int *)b; // Comparison function for qsort
>>>>>>> 98c87cb78a (data updated)
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Read the number of elements and the threshold k
    
    // Count occurrences of each integer
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    
    // Create an array to store non-zero counts
<<<<<<< HEAD
    int *a = (int*)malloc(SIZE * sizeof(int));
=======
    int *a = (int *)malloc(SIZE * sizeof(int));
>>>>>>> 98c87cb78a (data updated)
    int a_size = 0;

    // Filter non-zero counts and store them in array a
    for (int i = 0; i < SIZE; ++i) {
        if (cnt[i] > 0) {
            a[a_size++] = cnt[i];
        }
    }
    
    // Sort the array a in ascending order
    qsort(a, a_size, sizeof(int), compare);
    
    // Calculate the sum of the smallest k counts in array a
    int ans = 0;
    int m = a_size - k;
    for (int i = 0; i < m; ++i) {
        ans += a[i];
    }
    
    // Output the result
    printf("%d\n", ans);
    
    // Free allocated memory
    free(a);
    
    return 0;
}

// <END-OF-CODE>
