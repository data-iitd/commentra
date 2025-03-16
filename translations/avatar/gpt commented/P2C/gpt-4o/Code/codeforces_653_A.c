#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Read an integer input which represents the number of elements in the list
    int n;
    scanf("%d", &n);

    // Allocate memory for the list
    int *l = (int *)malloc(n * sizeof(int));

    // Read the elements into the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);
    }

    // Sort the list in ascending order
    qsort(l, n, sizeof(int), compare);

    // Iterate through each element in the sorted list
    for (int i = 0; i < n; i++) {
        // Check if both l[i] + 1 and l[i] + 2 exist in the list
        if (bsearch(&(l[i] + 1), l, n, sizeof(int), compare) &&
            bsearch(&(l[i] + 2), l, n, sizeof(int), compare)) {
            // If the condition is met, print 'YES' and exit the loop
            printf("YES\n");
            free(l);
            return 0;
        }
    }

    // If the loop completes without finding the condition, print 'NO'
    printf("NO\n");
    free(l);
    return 0;
}

// <END-OF-CODE>
