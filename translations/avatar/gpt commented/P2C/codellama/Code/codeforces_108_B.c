#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Read an input line (not used in the logic)
    char input[100];
    fgets(input, 100, stdin);
    
    // Read a line of integers, split by spaces, and convert them to a list of integers
    char* a[100];
    int i = 0;
    char* token = strtok(input, " ");
    while (token != NULL)
    {
        a[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    
    // Sort the list of integers in ascending order
    int j;
    for (i = 0; i < 100; i++)
    {
        for (j = i + 1; j < 100; j++)
        {
            if (atoi(a[i]) > atoi(a[j]))
            {
                char* temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    
    // Iterate through the sorted list starting from the second element
    for (i = 1; i < 100; i++)
    {
        // Check if the current element is different from the previous one
        // and if it is less than double the previous element
        if (atoi(a[i]) != atoi(a[i - 1]) && atoi(a[i]) < atoi(a[i - 1]) * 2)
        {
            // If the condition is met, return 'YES'
            printf("YES\n");
            return 0;
        }
    }
    
    // If no such pair is found, return 'NO'
    printf("NO\n");
    return 0;
}

