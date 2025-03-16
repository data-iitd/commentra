#include <stdio.h>

int main() {
    // Read an integer input which represents the number of lists to process
    int n;
    scanf("%d", &n);

    // Initialize a counter to keep track of lists with a sum greater than 1
    int c = 0;

    // Loop through the range of n to process each list
    for (int i = 0; i < n; i++) {
        // Read the size of the current list
        int size;
        scanf("%d", &size);
        
        // Initialize a variable to hold the sum of the current list
        int sum = 0;

        // Read the elements of the list and calculate the sum
        for (int j = 0; j < size; j++) {
            int num;
            scanf("%d", &num);
            sum += num;
        }

        // Check if the sum of the current list is greater than 1
        if (sum > 1) {
            // Increment the counter if the condition is met
            c++;
        }
    }

    // Print the final count of lists that had a sum greater than 1
    printf("%d\n", c);

    return 0;
}

// <END-OF-CODE>
