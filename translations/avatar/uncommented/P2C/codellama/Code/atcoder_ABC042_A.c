
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[100];
    int ABC[3];
    int i, j, count = 0;
    int sum = 0;

    printf("Enter the input: ");
    scanf("%s", input);

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            ABC[count] = atoi(input + i + 1);
            count++;
        }
    }

    for (i = 0; i < 3; i++)
    {
        if (ABC[i] == 5)
        {
            count++;
        }
    }

    if (count == 2)
    {
        for (i = 0; i < 3; i++)
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
        printf("NO\n");
    }

    return 0;
}

