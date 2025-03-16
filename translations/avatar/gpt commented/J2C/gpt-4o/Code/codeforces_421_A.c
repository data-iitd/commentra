#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables for the number of elements and sizes of the two lists
    int n, a, b;

    // Read the values for n, a, and b from the input
    scanf("%d %d %d", &n, &a, &b);

    // Initialize two arrays to store the elements of the two lists
    int *list1 = (int *)malloc(a * sizeof(int));
    int *list2 = (int *)malloc(b * sizeof(int));

    // Read 'a' integers into list1
    for (int i = 0; i < a; i++) {
        scanf("%d", &list1[i]);
    }

    // Read 'b' integers into list2
    for (int i = 0; i < b; i++) {
        scanf("%d", &list2[i]);
    }

    // Iterate from 0 to n-1 to check the presence of each index in list1
    for (int i = 0; i < n; i++) {
        int found = 0; // Flag to check if the current index + 1 is in list1
        for (int j = 0; j < a; j++) {
            if (list1[j] == i + 1) {
                found = 1; // Set flag if found
                break;
            }
        }
        // If the current index + 1 is in list1, print 1
        if (found) {
            printf("1 ");
        } else {
            // Otherwise, print 2
            printf("2 ");
        }
    }

    // Free allocated memory
    free(list1);
    free(list2);

    return 0;
}

// <END-OF-CODE>
