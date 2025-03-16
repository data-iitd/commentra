#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize an empty list 'li' to store the digits
    int *li = (int *)malloc(370 * sizeof(int));

    // Initialize an index variable 'ind'
    int ind = 0;

    // Iterate through the range from 1 to 370
    for (int i = 1; i <= 370; i++)
    {
        // Initialize an empty list 'temp' to store digits
        int *temp = (int *)malloc(370 * sizeof(int));

        // Assign current number 'i' to variables p and q
        int p = i, q = i;

        // Initialize a counter 'count' to keep track of number of digits
        int count = 0;

        // While p is not zero, divide it by 10 and increment the counter
        while (p != 0)
        {
            p /= 10;
            count++;
        }

        // Based on the number of digits, append the number or its digits to 'li'
        if (count == 1)
        {
            // If the number has only one digit, directly append it to 'li'
            li[ind++] = i;
        }
        else if (count == 2)
        {
            // If the number has two digits, extract its digits and reverse the list
            while (q != 0)
            {
                int x = q % 10; // Get the last digit
                q /= 10;        // Move to the previous digit
                temp[ind++] = x;
            }
            for (int j = ind - 1; j >= 0; j--)
            {
                li[ind++] = temp[j];
            }
        }
        else if (count == 3)
        {
            // If the number has three digits, extract its digits and reverse the list
            while (q != 0)
            {
                int x = q % 10; // Get the last digit
                q /= 10;        // Move to the previous digit
                temp[ind++] = x;
            }
            for (int j = ind - 1; j >= 0; j--)
            {
                li[ind++] = temp[j];
            }
        }
    }

    // Remove the first two elements from 'li' as they are not required
    ind -= 2;

    // Take an input 'n' from the user
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Print the required digit or digits from 'li' based on the user input
    printf("%d\n", li[n - 1]);

    // Free the memory allocated to 'li' and 'temp'
    free(li);
    free(temp);

    return 0;
}

