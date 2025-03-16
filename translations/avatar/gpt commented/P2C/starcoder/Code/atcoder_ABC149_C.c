#include <stdio.h>

int main()
{
    int X, i;
    scanf("%d", &X);
    int prime[100010] = {1};
    for (i = 2; i < 100010; i++)
        prime[i] = 1;
    for (i = 4; i < 100010; i += 2)
        prime[i] = 0;
    for (i = 3; i * i < 100008; i += 2)
        if (prime[i])
            for (int j = i * i; j < 100008; j += i)
                prime[j] = 0;
    for (i = X; i < 100008; i++)
        if (prime[i])
            printf("%d\n", i);
    return 0;
}

