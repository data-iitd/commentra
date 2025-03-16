#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Read the number of test cases 'n'
    int n;
    scanf("%d", &n);

    // Read the list 'l' of length 'n' containing 'n' integers
    int *l = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list 'l' in ascending order
    qsort(l, n, sizeof(int), compare);

    // Initialize variable 'c' to 0
    int c = 0;

    // Iterate through the list 'l'
    for (int i = 0; i < n; i++) {
        // If the current element 'l[i]' is greater than the previous count 'c', increment 'c' by 1
        if (l[i] > c) {
            c++;
        }
    }

    // Print the final result, which is the number of unique elements in the list 'l' plus 1
    printf("%d\n", c + 1);

    // Free allocated memory
    free(l);

    return 0;
}

// <END-OF-CODE>
