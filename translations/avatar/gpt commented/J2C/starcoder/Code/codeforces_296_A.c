#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int array[1001];
    for (int i = 0; i < n; i++)
    {
        int index;
        scanf("%d", &index);
        array[index]++;
    }
    int countMax = -1;
    for (int i = 1; i < 1001; i++)
    {
        if (countMax < array[i])
            countMax = array[i];
    }
    if (n % 2 == 0)
    {
        if (countMax <= n / 2)
            printf("YES");
        else
            printf("NO");
    }
    else
    {
        if (countMax <= n / 2 + 1)
            printf("YES");
        else
            printf("NO");
    }
    return 0;
}
