#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int ABC[3];
    int i;

    // Read a line of input
    fgets(input, 100, stdin);

    // Split the input into components
    char *token = strtok(input, " ");

    // Convert each component to an integer and store it in a tuple
    for (i = 0; i < 3; i++)
    {
        ABC[i] = atoi(token);
        token = strtok(NULL, " ");
    }

    // Check if the number 5 appears exactly twice in the tuple
    if (ABC[0] == 5 || ABC[1] == 5 || ABC[2] == 5)
    {
        // If 5 appears twice, check if the sum of the numbers in the tuple equals 17
        if (ABC[0] + ABC[1] + ABC[2] == 17)
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
        // If 5 does not appear exactly twice, print 'NO'
        printf("NO\n");
    }

    return 0;
}

