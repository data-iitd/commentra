
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 1000000
int main()
{
    int menu[MAX], i, j, n, e, ans = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &menu[i]);
        e = menu[i] % 10;
        if (e == 0)
            e = 10;
        menu[i] = (menu[i] - e) * 10 + e;
    }
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (menu[i] > menu[j])
            {
                int temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        ans += (int)ceil((double)menu[i] / 10) * 10;
    }
    printf("%d", ans + menu[0]);
    return 0;
}
