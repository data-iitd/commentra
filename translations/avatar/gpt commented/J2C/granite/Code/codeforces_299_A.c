
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object to read input from the user
    int n;
    scanf("%d", &n);

    // Initialize an array of size n to store the input values
    int *a = (int *)malloc(n * sizeof(int));

    // Loop to read n integers from the user and store them in the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Store the minimum value from the sorted array
    int min = a[0];

    // Check if all elements in the array are divisible by the minimum value
    for (int i = 0; i < n; i++) {
        if (a[i] % min!= 0) {
            // If any element is not divisible, print -1 and exit
            printf("-1\n");
            return 0;
        }
    }

    // If all elements are divisible, print the minimum value
    printf("%d\n", min);

    // Free the memory allocated for the array
    free(a);

    return 0;
}
