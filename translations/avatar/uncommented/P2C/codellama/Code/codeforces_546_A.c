
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char k[100], n[100], w[100];
    int i, total = 0;
    scanf("%s %s %s", k, n, w);
    for (i = 1; i <= atoi(w); i++)
    {
        total += i * atoi(k);
    }
    if (total > atoi(n))
    {
        printf("%d", total - atoi(n));
    }
    else
    {
        printf("0");
    }
    return 0;
}

