

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize an array of 4 integers and store them in ns array
    int ns[4];
    printf("Reading input\n");
    scanf("%d %d %d %d", &ns[0], &ns[1], &ns[2], &ns[3]);

    // Sort the ns array in ascending order
    printf("Sorting the numbers in ns array\n");
    qsort(ns, 4, sizeof(int), compare);

    // Check if the sorted ns array matches the specific condition (1, 4, 7, 9)
    printf("Checking the condition\n");
    if (ns[0] == 1 && ns[1] == 4 && ns[2] == 7 && ns[3] == 9) {
        printf("The condition is true, print YES\n");
        printf("Output: YES\n\n");
        printf("End of the program\n");
        return 0;
    } else {
        printf("The condition is false, print NO\n");
        printf("Output: NO\n\n");
        printf("End of the program\n");
        return 0;
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

