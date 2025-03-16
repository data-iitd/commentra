#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N;
    scanf("%d", &N);
    int m[368] = {0};
    int f[368] = {0};
    for (int i = 0; i < N; i++)
    {
        char x[2];
        int a, b;
        scanf("%s %d %d", x, &a, &b);
        if (x[0] == 'M')
        {
            m[a] += 2;
            m[b] -= 2;
        }
        else
        {
            f[a] += 2;
            f[b] -= 2;
        }
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < N; i++)
    {
        a += m[i];
        b += f[i];
        if (min(a, b) > c)
        {
            c = min(a, b);
        }
    }
    printf("%d\n", c);
    return 0;
}

