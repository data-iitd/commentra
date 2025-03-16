#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize an empty list to store the results
    int *li = (int *)malloc(sizeof(int) * 370);
    // Initialize an index variable
    int ind = 0;

    // Loop through numbers from 1 to 370
    for (int i = 1; i <= 370; i++)
    {
        // Initialize a temporary list to hold digits
        int *temp = (int *)malloc(sizeof(int) * 10);
        // Assign the current number to p and q for processing
        int p = i, q = i;
        // Initialize a count variable to track the number of digits
        int count = 0;

        // Count the number of digits in the current number i
        while (p!= 0)
        {
            p /= 10;  // Remove the last digit
            count++;  // Increment the digit count
        }

        // If the number has 1 digit, add it directly to the list
        if (count == 1)
        {
            li[ind] = i;
            ind++;
        }

        // If the number has 2 digits
        if (count == 2)
        {
            // Reset the temporary list
            for (int j = 0; j < 10; j++)
            {
                temp[j] = 0;
            }
            // Extract digits of the number q
            while (q!= 0)
            {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp[x - 1] = x;  // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            for (int j = 9; j >= 0; j--)
            {
                li[ind] = temp[j];
                ind++;
            }
        }

        // If the number has 3 digits
        if (count == 3)
        {
            // Reset the temporary list
            for (int j = 0; j < 10; j++)
            {
                temp[j] = 0;
            }
            // Extract digits of the number q
            while (q!= 0)
            {
                int x = q % 10;  // Get the last digit
                q /= 10;  // Remove the last digit
                temp[x - 1] = x;  // Append the digit to the temporary list
            }
            // Add the digits in reverse order to the main list
            for (int j = 9; j >= 0; j--)
            {
                li[ind] = temp[j];
                ind++;
            }
        }
    }

    // Remove the last two elements from the list (not specified why)
    li[ind - 2] = 0;
    li[ind - 1] = 0;

    // Take user input for the index
    int n = atoi(input(""));
    // Print the n-th element from the list (1-based index)
    printf("%d\n", li[n - 1]);

    return 0;
}

