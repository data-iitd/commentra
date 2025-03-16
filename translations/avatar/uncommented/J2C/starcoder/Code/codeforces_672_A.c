#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[1000];
    for (int i = 1; i <= 1000; i++)
    {
        str[i - 1] = i;
    }
    printf("%c", str[n - 1]);
    return 0;
}
