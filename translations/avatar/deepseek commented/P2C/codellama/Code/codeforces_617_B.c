
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char a[100];
    int i, j, count = 0;
    double result = 1;

    // Take an input from the user and store it in variable 'a'
    scanf("%s", a);

    // Print the result based on the input
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '1')
        {
            count++;
        }
    }
    if (count == 0)
    {
        printf("0");
    }
    else
    {
        for (i = 0; a[i] != '\0'; i++)
        {
            if (a[i] == '1')
            {
                for (j = i + 1; a[j] != '\0'; j++)
                {
                    if (a[j] == '0')
                    {
                        count++;
                    }
                }
                result = result * count;
                count = 0;
            }
        }
        printf("%.0lf", result);
    }
    return 0;
}

