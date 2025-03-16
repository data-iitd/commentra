
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, x;
    scanf("%d %d", &n, &x);
    print(x, n);
    return 0;
}

void print(int x, int n)
{
    int max = n * 2 - 1;
    if (x == 1 || x == max)
    {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    char *ans = (char *)malloc(sizeof(char) * (max + 1));
    for (int i = x + n - 1; i < x + n + max - 1; i++)
    {
        ans[i % max + 1] = (i % max + 1) + '\n';
    }
    printf("%s", ans);
    free(ans);
}

