#include <stdio.h>

int main()
{
    int n, d, m = 0, q = 0;
    scanf("%d %d", &n, &d);
    int x[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (int a = 0; a < n - 1; a++)
    {
        if (x[a] >= x[a + 1])
        {
            q = (x[a] - x[a + 1]) / d + 1;
            m = m + q;
            x[a + 1] = x[a + 1] + q * d;
        }
    }
    printf("%d", m);
    return 0;
}
