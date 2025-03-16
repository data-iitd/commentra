#include <stdio.h>
int main()
{
    int a, b, t, cookie, time;
    scanf("%d %d %d", &a, &b, &t);
    cookie = 0;
    time = a;
    while (time <= t + 0.5)
    {
        cookie += b;
        time += a;
    }
    printf("%d", cookie);
    return 0;
}
