#include <stdio.h>

int main()
{
    // Take an integer 'n' as input from the user
    int n;
    scanf("%d", &n);

    // Initialize a counter 'c' to 0
    int c = 0;

    // Iterate through the range of 'n'
    for (int i = 0; i < n; i++)
    {
        // Take 'n' lists of integers as input from the user
        int l1[100];
        for (int j = 0; j < 100; j++)
        {
            scanf("%d", &l1[j]);
        }

        // Check if the sum of the elements in the current list is greater than 1
        int sum = 0;
        for (int j = 0; j < 100; j++)
        {
            sum += l1[j];
        }
        if (sum > 1)
        {
            // Increment the counter 'c' by 1 if the condition is true
            c++;
        }
    }

    // Print the value of the counter 'c'
    printf("%d", c);

    return 0;
}
