
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize variables
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b); // Read the number of test cases and the sizes of the lists

    // Create arrays to store the lists
    int list1[a];
    int list2[b];

    // Read and store the elements of the first and second lists
    for (int i = 0; i < a; i++) {
        scanf("%d", &list1[i]); // Read and store an element in list1
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &list2[i]); // Read and store an element in list2
    }

    // Iterate through the input array and print the corresponding number based on the presence of the element in list1
    for (int i = 0; i < n; i++) {
        int found = 0; // Initialize a flag to check if the element is present in list1
        for (int j = 0; j < a; j++) {
            if (list1[j] == i + 1) { // Check if the current input element is present in list1
                found = 1; // Set the flag to 1 if the element is found
                break; // Exit the loop if the element is found
            }
        }
        if (found) { // If the element is found in list1
            printf("1 "); // Print 1
        } else {
            printf("2 "); // Print 2
        }
    }

    return 0;
}

Translate the above C code to Python and end with comment "