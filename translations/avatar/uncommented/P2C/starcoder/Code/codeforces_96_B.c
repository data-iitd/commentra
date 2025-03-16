#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#define MAX 10000000000

int main()
{
    int l[MAX];
    int limit = 10000000000;
    int i = 0;
    int four = 0;
    int seven = 0;
    int number = 0;
    int n = 0;
    int ans = 0;
    while (number <= limit)
    {
        if (number > 0 && four == seven)
        {
            l[i] = number;
            i++;
        }
        number = number * 10 + 4;
        four++;
        if (number > limit)
        {
            break;
        }
        number = number * 10 + 7;
        seven++;
    }
    qsort(l, i, sizeof(int), compare);
    n = atoi(input());
    for (int j = 0; j < i; j++)
    {
        if (l[j] >= n)
        {
            ans = l[j];
            break;
        }
    }
    printf("%d", ans);
    return 0;
}

