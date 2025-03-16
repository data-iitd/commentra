#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare and initialize variables
    int n, a, b;
    
    // Read the number of test cases, number of elements in the first list, and number of elements in the second list
    scanf("%d %d %d", &n, &a, &b);

    // Create arrays to store the lists
    int *list1 = (int *)malloc(a * sizeof(int));
    int *list2 = (int *)malloc(b * sizeof(int));

    // Read and store the elements of the first and second lists
    for (int i = 0; i < a; i++) {
        scanf("%d", &list1[i]); // Read and add an element to list1
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &list2[i]); // Read and add an element to list2
    }

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for (int i = 0; i < n; i++) {
        int found = 0; // Flag to check presence in list1
        for (int j = 0; j < a; j++) {
            if (list1[j] == (i + 1)) { // Check if the current input element is present in list1
                found = 1; // Set flag if found
                break;
            }
        }
        if (found) {
            printf("1 "); // If present, print 1
        } else {
            printf("2 "); // If not present, print 2
        }
    }

    // Free allocated memory
    free(list1);
    free(list2);

    return 0;
}

// <END-OF-CODE>
