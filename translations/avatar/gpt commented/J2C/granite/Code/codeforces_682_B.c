
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a Scanner object for input and a PrintWriter for output
    int n;
    scanf("%d", &n);
    int *list = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // Initialize an ArrayList to store the input integers
    // Read n integers from input and add them to the list
    // Sort the list of integers in ascending order
    // Initialize a counter to track the maximum consecutive integer
    // Iterate through the sorted list to find the maximum consecutive integer
    // Print the result which is the maximum consecutive integer found
    // Close the PrintWriter
    // Debugging method to print objects to the error output

    // Print the result which is the maximum consecutive integer found
    printf("%d\n", c);

    // Close the PrintWriter
    // Debugging method to print objects to the error output

    // Free the memory allocated for the list
    free(list);

    return 0;
}

// Debugging method to print objects to the error output
void debug(Object... obj) {
    fprintf(stderr, "%s\n", Arrays.deepToString(obj));
}

// End of code
