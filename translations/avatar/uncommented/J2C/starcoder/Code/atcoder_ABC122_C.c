#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q, frag[1000001], rui[1000001];
    char c[1000001];
    scanf("%d %d", &n, &q);
    scanf("%s", c);
    for (int i = 2; i <= n; i++)
    {
        if (c[i - 2] == 'A' && c[i - 1] == 'C')
            frag[i]++;
        rui[i] = rui[i - 1] + frag[i];
    }
    for (int i = 0; i < q; i++)
    {
        int left, right;
        scanf("%d %d", &left, &right);
        printf("%d\n", rui[right] - rui[left]);
    }
    return 0;
}

