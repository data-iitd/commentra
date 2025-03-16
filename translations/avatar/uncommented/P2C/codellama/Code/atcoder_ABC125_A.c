
#include <stdio.h>
int main()
{
    int a, b, t;
    float cookie = 0, time = 0;
    scanf("%d %d %d", &a, &b, &t);
    while (time <= t + 0.5)
    {
        cookie += b;
        time += a;
    }
    printf("%.0f", cookie);
    return 0;
}
