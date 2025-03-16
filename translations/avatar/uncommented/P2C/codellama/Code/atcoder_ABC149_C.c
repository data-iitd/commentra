
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int X;
    bool prime[100010];
    int i, j;

    scanf("%d", &X);

    for (i = 0; i < 100010; i++)
    {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (i = 4; i < 100010; i += 2)
    {
        prime[i] = false;
    }

    i = 3;
    while (i * i <= 100008)
    {
        if (prime[i])
        {
            for (j = i + i; j <= 100008; j += i)
            {
                prime[j] = false;
            }
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

