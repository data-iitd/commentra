#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[1000];
    int i, j, k, count = 0, product_of_zeros = 1;

    // Read the input from the standard input
    scanf("%s", a);

    // Check if the string contains any '1' character
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '1')
        {
            // If it doesn't, print 0 and exit the program
            printf("0");
            return 0;
        }
    }

    // If the string contains at least one '1' character, we proceed to calculate the product of the number of zeros in each segment between consecutive '1' characters
    for (i = 0; a[i] != '\0'; i++)
    {
        if (a[i] == '1')
        {
            count = 0;
            for (j = i + 1; a[j] != '\0'; j++)
            {
                if (a[j] == '0')
                {
                    count++;
                }
                else
                {
                    break;
                }
            }
            product_of_zeros *= count + 1;
        }
    }

    // Finally, print the result
    printf("%d", product_of_zeros);

    return 0;
}

