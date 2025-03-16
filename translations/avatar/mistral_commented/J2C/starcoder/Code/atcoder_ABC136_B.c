#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N, count, temp, ans = 0;
    scanf("%d", &N);
    count = 0;
    temp = N;
    while (temp > 0)
    {
        temp /= 10;
        count++;
    }
    for (int i = 1; i <= count; i++)
    {
        if (i == count)
        {
            if (i % 2 == 1)
            {
                ans += (N - pow(10, i - 1) + 1);
            }
        }
        else
        {
            if (i == 1)
            {
                ans += 9;
            }
            else if (i % 2 == 1)
            {
                ans += (pow(10, i) - pow(10, i - 1));
            }
        }
    }
    printf("%d", ans);
    return 0;
}

