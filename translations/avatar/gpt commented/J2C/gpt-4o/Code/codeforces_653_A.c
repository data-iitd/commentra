#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the number of integers

    int *a = (int *)malloc(n * sizeof(int)); // Allocate memory for the integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Read n integers
    }

    // Remove duplicates by sorting and then filtering
    qsort(a, n, sizeof(int), compare);
    
    // Count unique elements
    int unique_count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            a[unique_count++] = a[i]; // Keep unique elements
        }
    }

    // Check for three consecutive integers
    int found = 0; // Flag to check for consecutive triplets
    for (int i = 0; i < unique_count - 2; i++) {
        if (a[i] + 1 == a[i + 1] && a[i + 1] + 1 == a[i + 2]) {
            found = 1; // Set found to true if consecutive triplet is found
            break;
        }
    }

    // Output "YES" if a triplet was found, otherwise output "NO"
    printf(found ? "YES\n" : "NO\n");

    free(a); // Free allocated memory
    return 0;
}
