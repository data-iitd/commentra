
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, t, cookie = 0, time = 0;
    scanf("%d %d %d", &a, &b, &t);
    while (time <= t + 0.5)
    {
        cookie += b;
        time += a;
    }
    printf("%d", cookie);
    return 0;
}

