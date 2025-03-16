#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, sum = 0;
    char *input, *token;

    // Read user input and assign it to the variable 'n'
    scanf("%d", &n);

    // Create a list 'list' with the same length as 'n'
    // Each element in the list is the remainder of the corresponding input value divided by 2
    int list[n];
    for (i = 0; i < n; i++)
    {
        list[i] = (int)strtol(strtok(NULL, " "), NULL, 10) % 2;
    }

    // Check if the sum of all elements in the list is equal to 1
    for (i = 0; i < n; i++)
    {
        sum += list[i];
    }
    if (sum == 1)
    {
        // If the condition is true, print the index of the first occurrence of the number 1 in the list
        for (i = 0; i < n; i++)
        {
            if (list[i] == 1)
            {
                printf("The first number with remainder 1 is: %d\n", i + 1);
                break;
            }
        }
    }
    else
    {
        // If the condition is false, print the index of the first occurrence of the number 0 in the list
        for (i = 0; i < n; i++)
        {
            if (list[i] == 0)
            {
                printf("The first number with remainder 0 is: %d\n", i + 1);
                break;
            }
        }
    }

    return 0;
}

