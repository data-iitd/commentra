
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int X, i, j;
    int *prime;

    X = atoi(input());
    prime = (int *)malloc(sizeof(int) * 100010);

    for (i = 0; i < 100010; i++)
        prime[i] = 1;

    prime[0] = 0;
    prime[1] = 0;

    for (i = 4; i < 100010; i += 2)
        prime[i] = 0;

    i = 3;
    while (i * i <= 100008)
    {
        if (prime[i])
        {
            for (j = i + i; j < 100008; j += i)
                prime[j] = 0;
        }
        i += 2;
    }

    for (i = X; i < 100008; i++)
    {
        if (prime[i])
        {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}

