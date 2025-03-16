#include <stdio.h>
#include <stdlib.h>

void s() {
    // Read input as a list of integers
    int input_list[100]; // Assuming a maximum of 100 integers
    int n = 0;

    // Read integers from input
    while (scanf("%d", &input_list[n]) != EOF) {
        n++;
    }

    // Sort the input list in ascending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (input_list[j] > input_list[j + 1]) {
                int temp = input_list[j];
                input_list[j] = input_list[j + 1];
                input_list[j + 1] = temp;
            }
        }
    }

    // Initialize a variable to store the result
    char *result = "NO";

    // Iterate through the sorted list starting from the second element
    for (int i = 1; i < n; i++) {
        // Compare the current element with the previous one
        int current_element = input_list[i];
        int previous_element = input_list[i - 1];

        // Check if the current element is less than twice the previous element
        // and if it is not equal to the previous element
        if (current_element < previous_element * 2 && current_element != previous_element) {
            // If the condition is true, set the result to "YES"
            result = "YES";
            break; // Break out of the loop since we have found the answer
        }
    }

    // Print the result
    printf("%s\n", result);
}

int main() {
    s();
    return 0;
}

// <END-OF-CODE>
