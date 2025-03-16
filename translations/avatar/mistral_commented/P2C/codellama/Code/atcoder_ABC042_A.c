#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define a tuple 'ABC' by applying int() function to each element of a list obtained by splitting a user input by space
    int ABC[3];
    char input[100];
    scanf("%s", input);
    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL)
    {
        ABC[i] = atoi(token);
        token = strtok(NULL, " ");
        i++;
    }

    // Check if the tuple 'ABC' contains exactly 2 occurrences of the integer '5' using the count() method
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        if (ABC[i] == 5)
        {
            count++;
        }
    }
    if (count == 2)
    {
        // If the condition is met, print 'YES' if the sum of all elements in the tuple 'ABC' equals '17'
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += ABC[i];
        }
        if (sum == 17)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    else
    {
        // If the condition is not met, print 'NO'
        printf("NO\n");
    }

    return 0;
}

