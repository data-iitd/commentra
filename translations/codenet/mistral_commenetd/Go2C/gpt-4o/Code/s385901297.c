#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    // Initialize an array to store the integers
    int ns[4];

    // Read the first line of input containing 4 integers
    printf("Reading input\n");
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

    // Sort the ns array in ascending order
    printf("Sorting the numbers in ns slice\n");
    qsort(ns, 4, sizeof(int), compare);

    // Check if the sorted ns array matches the specific condition (1, 4, 7, 9)
    printf("Checking the condition\n");
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("The condition is true, print YES\n");
        printf("Output: YES\n");
    } else {
        printf("The condition is false, print NO\n");
        printf("Output: NO\n");
    }

    printf("\nEnd of the program\n");
    return 0;
}

// <END-OF-CODE>
