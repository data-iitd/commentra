#include <stdio.h>
#include <stdlib.h>

// Define the main function
int main(int argc, char *argv[])
{
    // Read the number of test cases
    int n = atoi(argv[1]);

    // Read the array of integers
    int *a = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = atoi(argv[i + 2]);
    }

    // Initialize variables
    int current_level = 0;
    int counter = 0;
    int counter_turns = -1;

    // Main loop
    while (counter < n)
    {
        // Increment turns counter
        counter_turns += 1;

        // Iterate through the array
        for (int i = 0; i < n; i++)
        {
            // If current index is valid and its value is less than or equal to current level
            if (a[i]!= -1 && a[i] <= counter)
            {
                // Increment counter and mark the index as visited
                counter += 1;
                a[i] = -1;
            }
        }

        // Reverse the array
        for (int i = 0; i < n / 2; i++)
        {
            int temp = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = temp;
        }
    }

    // Print the result
    printf("%d\n", counter_turns);

    // Free the memory
    free(a);

    // Return from the main function
    return 0;
}

