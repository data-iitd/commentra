// Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the main function
int main() {
    // Initialize variables
    int n, a, b;
    int i, j;
    int *list1, *list2;

    // Read the number of test cases
    scanf("%d", &n);

    // Read the number of elements in the first list
    scanf("%d", &a);

    // Read the number of elements in the second list
    scanf("%d", &b);

    // Allocate memory for the lists
    list1 = (int *)malloc(a * sizeof(int));
    list2 = (int *)malloc(b * sizeof(int));

    // Read and store the elements of the first and second lists
    for (i = 0; i < a; i++) {
        scanf("%d", &list1[i]);
    }
    for (i = 0; i < b; i++) {
        scanf("%d", &list2[i]);
    }

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for (i = 0; i < n; i++) {
        if (list1[i] == 1) {
            printf("1 ");
        } else {
            printf("2 ");
        }
    }

    // Free the memory allocated for the lists
    free(list1);
    free(list2);

    // End the program
    return 0;
}

