#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize an empty list to store the results
    int *li = NULL;
    // Initialize an index variable
    int ind = 0;

    // Loop through numbers from 1 to 370
    for (int i = 1; i <= 370; i++)
    {
        // Initialize a temporary list to hold digits
        int *temp = NULL;
        // Assign the current number to p and q for processing
        int p = i, q = i;
        // Initialize a count variable to track the number of digits
        int count = 0;

        // Count the number of digits in the current number i
        while (p != 0)
        {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the list
        if (count == 1)
        {
            li = (int *)realloc(li, (ind + 1) * sizeof(int));
            li[ind++] = i;
        }

        // If the number has 2 digits
        if (count == 2)
        {
            temp = (int *)realloc(temp, 2 * sizeof(int));
            // Extract digits of the number q
            while (q != 0)
            {
                int x = q % 10;  // Get the last digit
                q /= 10;         // Remove the last digit
                temp[1 - (q % 2)] = x; // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            li = (int *)realloc(li, (ind + 2) * sizeof(int));
            li[ind++] = temp[1];
            li[ind++] = temp[0];
        }

        // If the number has 3 digits
        if (count == 3)
        {
            temp = (int *)realloc(temp, 3 * sizeof(int));
            // Extract digits of the number q
            while (q != 0)
            {
                int x = q % 10;  // Get the last digit
                q /= 10;         // Remove the last digit
                temp[2 - (q % 3)] = x; // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            li = (int *)realloc(li, (ind + 3) * sizeof(int));
            li[ind++] = temp[2];
            li[ind++] = temp[1];
            li[ind++] = temp[0];
        }
    }

    // Remove the last two elements from the list (not specified why)
    ind -= 2;

    // Take user input for the index
    int n;
    scanf("%d", &n);
    // Print the n-th element from the list (1-based index)
    printf("%d\n", li[n - 1]);

    // Free the memory allocated for the list
    free(li);
    free(temp);

    return 0;
}

