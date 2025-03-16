#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000 // Define a maximum size for the lists

// Function to compare two long integers for qsort
int compare(const void *a, const void *b) {
    return (*(long *)a - *(long *)b);
}

int main() {
    int x[3]; // Declaring an integer array x of size 3
    int max = 0; // Initializing max to 0

    // Reading the size of the array x from the standard input stream
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &x[i]); // Reading the i-th element of the array x
        if (x[i] > max) {
            max = x[i]; // Finding the maximum element of the array x
        }
    }

    int k; // Variable to hold the integer k
    scanf("%d", &k); // Reading the integer k from the standard input stream

    long *a[3]; // Declaring an array a of size 3, where each element is a pointer to long
    int sizes[3]; // Array to hold the sizes of each sub-list

    // Reading the elements of each sub-list a[i] from the standard input stream and sorting it
    for (int i = 0; i < 3; ++i) {
        sizes[i] = x[i];
        a[i] = (long *)malloc(sizes[i] * sizeof(long)); // Allocating memory for each sub-list
        for (int j = 0; j < sizes[i]; ++j) {
            scanf("%ld", &a[i][j]); // Reading the j-th element of the sub-list a[i]
        }
        qsort(a[i], sizes[i], sizeof(long), compare); // Sorting the sub-list in ascending order
    }

    // List to store the sums
    long *ans = (long *)malloc(MAX_SIZE * sizeof(long)); // Allocating memory for the answer list
    int ans_size = 0; // Size of the answer list

    // Finding all such sums and adding them to the list ans
    for (int i = 0; i < sizes[0]; ++i) {
        for (int j = 0; j < sizes[1]; ++j) {
            for (int m = 0; m < sizes[2]; ++m) {
                if ((i + 1) * (j + 1) * (m + 1) <= k) { // Checking the product condition
                    long tmp = a[0][sizes[0] - i - 1] // Getting the (sizes[0]-i)-th element of a[0]
                             + a[1][sizes[1] - j - 1] // Getting the (sizes[1]-j)-th element of a[1]
                             + a[2][sizes[2] - m - 1]; // Getting the (sizes[2]-m)-th element of a[2]
                    ans[ans_size++] = tmp; // Adding the sum to the list ans
                }
            }
        }
    }

    // Sorting the answer list in ascending order
    qsort(ans, ans_size, sizeof(long), compare);

    // Printing the elements of the list ans in descending order
    for (int i = 0; i < ans_size && i < k; ++i) {
        printf("%ld\n", ans[ans_size - i - 1]); // Printing the i-th element from the end
    }

    // Freeing allocated memory
    for (int i = 0; i < 3; ++i) {
        free(a[i]); // Freeing each sub-list
    }
    free(ans); // Freeing the answer list

    return 0; // Returning 0 to indicate successful execution
}

// <END-OF-CODE>
