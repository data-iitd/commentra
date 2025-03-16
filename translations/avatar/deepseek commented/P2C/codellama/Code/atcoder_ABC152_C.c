
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, i, j, a, pos;
    scanf("%d", &N);
    int n[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &n[i]);
    }
    a = 1;
    pos = 0;
    for (i = 1; i < N; i++)
    {
        if (n[pos] > n[i])
        {
            a += 1;
            pos = i;
        }
    }
    printf("%d", a);
    return 0;
}
