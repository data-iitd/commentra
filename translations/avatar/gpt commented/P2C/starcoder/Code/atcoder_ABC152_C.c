#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, a, pos, i;
    scanf("%d", &N);
    int n[N];
    for (i = 0; i < N; i++)
        scanf("%d", &n[i]);
    a = 1;
    pos = 0;
    for (i = 1; i < N; i++)
    {
        if (n[pos] > n[i])
        {
            a++;
            pos = i;
        }
    }
    printf("%d", a);
    return 0;
}
