#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, sa, a, b;
    char *ss;
    scanf("%d %d", &n, &m);
    sa = 0;
    for (int i = 0; i < n; i++)
        if (getchar() == '-')
            sa++;
    ss = (char *)malloc(m * sizeof(char));
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        b -= a;
        ss[i] = (b % 2 && b <= sa << 1)? '1' : '0';
    }
    printf("%s", ss);
    free(ss);
    return 0;
}
