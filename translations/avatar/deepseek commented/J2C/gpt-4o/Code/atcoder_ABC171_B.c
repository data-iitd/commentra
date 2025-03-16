#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k); // Reads the number of elements (n) and the number of elements to consider (k)
    
    int *a = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]); // Reads the elements into an array
    }
    
    qsort(a, n, sizeof(int), compare); // Sorts the array using qsort
    
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += a[i]; // Sums the first k elements
    }
    
    printf("%d\n", ans); // Prints the result
    
    free(a); // Free the allocated memory
    return 0;
}

// <END-OF-CODE>
