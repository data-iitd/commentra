#include <stdio.h>
#include <stdlib.h>

// Define a function named s that takes no arguments
void s() {

    // Declare a variable to store the size of the input list
    int n;

    // Read the size of the input list
    scanf("%d", &n);

    // Declare an array to store the input list
    int input_list[n];

    // Read the input list as integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &input_list[i]);
    }

    // Sort the input list in ascending order
    qsort(input_list, n, sizeof(int), (int (*)(const void *, const void *))compare);

    // Initialize a variable to store the result
    char result[] = "NO";

    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < n; i++) {

        // Compare the current element with the previous one
        int current_element = input_list[i];
        int previous_element = input_list[i - 1];

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if (current_element < previous_element * 2 && current_element != previous_element) {

            // If the condition is true, set the result to 'YES'
            result[0] = 'Y';
            result[1] = 'E';
            result[2] = 'S';

            // Break out of the loop since we have found the answer
            break;
        }
    }

    // Print the result
    printf("%s\n", result);
}

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

