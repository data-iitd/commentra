#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n); // Read the size of the array
    int *a = (int *)malloc(n * sizeof(int)); // Initialize the array of size n
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]); // Populate the array with n integers
    }
    
    qsort(a, n, sizeof(int), compare); // Sort the array

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i] * 2 && a[i] != a[i + 1]) { // Check if any element is less than twice the previous element
            printf("YES\n");
            free(a); // Free allocated memory
            return 0; // Exit the program after printing "YES"
        }
    }
    
    printf("NO\n"); // Print "NO" if no such condition is found
    free(a); // Free allocated memory
    return 0;
}

// <END-OF-CODE>
