#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, t, i;

    scanf("%d", &k);

    t = 0;

    for (i = 1; i <= k; i++)
    {
        t = (t * 10 + 7) % k;

        if (t == 0)
        {
            printf("%d\n", i);
            break;
        }
    }

    if (t!= 0)
        printf("-1\n");

    return 0;
}

