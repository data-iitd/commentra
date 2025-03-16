#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    // Compare function for qsort to sort in descending order based on the second element of the tuples
    int *tupleA = (int *)a;
    int *tupleB = (int *)b;
    return tupleB[1] - tupleA[1]; // Sort by second element in descending order
}

int main() {
    int n;
    printf("Enter the number of tuples: ");
    scanf("%d", &n);

    int m[n][2]; // Create a 2D array to hold the tuples

    for (int i = 0; i < n; i++) {
        printf("Enter tuple %d: ", i + 1);
        scanf("%d %d", &m[i][0], &m[i][1]); // Read each tuple
    }

    qsort(m, n, sizeof(m[0]), compare); // Sort the array of tuples

    int *a = m[0]; // Initialize 'a' with the first tuple in the sorted array

    for (int i = 1; i < n; i++) {
        if (m[i][1] > a[1]) {
            printf("Happy Alex\n");
            return 0; // Exit the program if condition is met
        }
        a = m[i]; // Update 'a' to the current tuple
    }

    printf("Poor Alex\n"); // If no tuple met the condition, print this message
    return 0;
}

// <END-OF-CODE>
