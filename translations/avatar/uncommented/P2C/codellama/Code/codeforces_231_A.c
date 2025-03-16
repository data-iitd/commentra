#include <stdio.h>
int main()
{
    int n, i, c = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int l1[100], j;
        scanf("%d", &l1[i]);
        if (l1[i] > 1)
            c++;
    }
    printf("%d", c);
    return 0;
}
