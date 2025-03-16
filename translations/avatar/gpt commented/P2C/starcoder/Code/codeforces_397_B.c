#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, i, j, k, a, b, c;
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        k = a / b;
        printf("%s\n", k * c >= a? "Yes" : "No");
    }
    return 0;
}
