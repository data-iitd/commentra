

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;  // Number of elements
    scanf("%d", &n);  // Take an integer input for the number of elements

    int *l = (int *)malloc(n * sizeof(int));  // Allocate memory for the list of integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &l[i]);  // Take a list of integers as input
    }

    qsort(l, n, sizeof(int));  // Sort the list of integers

    int found = 0;  // Variable to check if any integer i exists such that i + 1 and i + 2 are also in the list
    for (int i = 0; i < n - 2; i++) {
        if (l[i + 1] - l[i] == 1 && l[i + 2] - l[i + 1] == 1) {  // Check if i + 1 and i + 2 are in the list
            found = 1;  // Set found to 1 if found
            break;
        }
    }

    if (found) {
        printf("YES\n");  // If found, print 'YES'
    } else {
        printf("NO\n");  // If no such integer is found, print 'NO'
    }

    free(l);  // Free the allocated memory
    return 0;
}
