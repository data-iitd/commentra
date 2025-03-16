

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int n, x, *l, tmpL, tmpSum, rs, i, j, tmp;

    // Read input values for n and x
    printf("Enter the number of arrays:\n");
    scanf("%d", &n);
    printf("Enter the sum of elements in an array that should not exceed:\n");
    scanf("%d", &x);

    // Initialize an empty array l to store the arrays
    l = (int*)malloc(n * sizeof(int));

    // Read input values for each array and store them in the array l
    for (i = 0; i < n; i++) {
        // Read the length of the current array
        printf("Enter the length of array number %d:\n", i+1);
        scanf("%d", &tmpL);

        // Store the length of the current array in the array l
        l[i] = tmpL;
    }

    // Initialize variables for sum and result slice index
    tmpSum = 0;
    rs = 0;

    // Iterate through the array l to find the index of the last array whose sum is less than or equal to x
    for (i = 0; i < n; i++) {
        // Initialize a variable tmpSum to store the sum of elements in the current array
        tmpSum = 0;

        // Calculate the sum of elements in the current array
        for (j = 0; j < l[i]; j++) {
            // Read the value of the current element and add it to the sum
            printf("Enter the value of element number %d in array number %d:\n", j+1, i+1);
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

    // Free the memory allocated for the array l
    free(l);

    return 0;
}
