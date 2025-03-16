#include <stdio.h>

int main() {
    // Initialize variables
    int n, x;
    int *l;

    // Read input values for n and x
    printf("Enter the number of arrays:\n");
    scanf("%d", &n);
    printf("Enter the sum of elements in an array that should not exceed:\n");
    scanf("%d", &x);

    // Allocate memory for the array lengths
    l = (int *)malloc(n * sizeof(int));

    // Read input values for each array and store them in the array l
    for (int i = 0; i < n; i++) {
        // Read the length of the current array
        printf("Enter the length of array number %d:\n", i + 1);
        scanf("%d", &l[i]);
    }

    // Initialize variables for sum and result slice index
    int tmpSum;
    int rs = 0;

    // Iterate through the array l to find the index of the last array whose sum is less than or equal to x
    for (int i = 0; i < n; i++) {
        // Initialize a variable tmpSum to store the sum of elements in the current array
        tmpSum = 0;

        // Calculate the sum of elements in the current array
        for (int j = 0; j < l[i]; j++) {
            // Read the value of the current element and add it to the sum
            int tmp;
            printf("Enter the value of element number %d in array number %d:\n", j + 1, i + 1);
            scanf("%d", &tmp);
            tmpSum += tmp;
        }

        // Check if the sum of elements in the current array is greater than x
        if (tmpSum > x) {
            // If yes, break the loop as we don't need to check further arrays
            break;
        }

        // If the sum of elements in the current array is less than or equal to x, update the result slice index
        rs = i + 1;
    }

    // Print the result slice index
    printf("The last array index whose sum of elements is less than or equal to %d is: %d\n", x, rs);

    // Free allocated memory
    free(l);

    return 0;
}

// <END-OF-CODE>
