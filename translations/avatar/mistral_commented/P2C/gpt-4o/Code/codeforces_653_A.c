#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b;
}

int main() {
    int n;
    scanf("%d", &n);  // Read the number of elements in the list
    int *l = (int *)malloc(n * sizeof(int));  // Allocate memory for the list

    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // Read the list of integers
    }

    qsort(l, n, sizeof(int), compare);  // Sort the list in ascending order

    for (int i = 0; i < n; i++) {  // Iterate through each element in the sorted list
        if (bsearch(&(l[i] + 1), l, n, sizeof(int), compare) &&
            bsearch(&(l[i] + 2), l, n, sizeof(int), compare)) {  // Check if the next two elements are also in the list
            printf("YES\n");  // If yes, print 'YES' and break out of the loop
            free(l);  // Free allocated memory
            return 0;  // Exit the program
        }
    }

    printf("NO\n");  // If no, print 'NO' after the loop finishes
    free(l);  // Free allocated memory
    return 0;
}
