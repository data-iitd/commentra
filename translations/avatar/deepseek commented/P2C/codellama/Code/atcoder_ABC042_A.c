
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[100];
    int ABC[3];
    int i;

    // Take input from user
    printf("Enter the input: ");
    scanf("%s", input);

    // Split the input into integers
    for (i = 0; i < 3; i++)
    {
        ABC[i] = atoi(strtok(input, " "));
    }

    // Check if the tuple contains exactly two 5s
    if (ABC[0] == 5 && ABC[1] == 5)
    {
        // Check if the sum of the elements in ABC is 17
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
        printf("NO\n");
    }

    return 0;
}

