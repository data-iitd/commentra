#include <stdio.h>
#include <stdlib.h>

public class Main {
    public static void main(String[] args) {
        int a, c, k, b; // Declare variables: a for input, c for counting, k for groups of three, b for temporary storage

        // Continuously read integers from standard input until EOF
        while (~scanf("%d", &a))
        {
            c = 0; // Initialize count of individual items
            k = 0; // Initialize count of groups of three

            // Check if the input number is less than 3
            if (a < 3)
                printf("0\n"); // If less than 3, print 0 (no groups can be formed)
            else
            {
                b = a; // Store the original value of a in b for later use

                // Loop to count down from a to 0
                while (a--)
                {
                    b--; // Decrement b
                    c++; // Increment the count of items

                    // Check if we have counted three items
                    if (c == 3)
                    {
                        k++; // Increment the count of groups of three
                        c = 0; // Reset the count of items for the next group
                    }
                }
                // Print the total number of groups of three formed
                printf("%d\n", k);
            }
        }

        return 0; // Return success status
    }
}

