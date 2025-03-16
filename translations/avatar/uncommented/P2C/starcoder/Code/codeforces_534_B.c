#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int v1, v2, t, d, a, v, distance;
    scanf("%d %d", &v1, &v2);
    scanf("%d %d", &t, &d);
    v1 = atoi(argv[1]);
    v2 = atoi(argv[2]);
    t = atoi(argv[3]);
    d = atoi(argv[4]);
    a = 1;
    v = v1;
    distance = 0;
    for (int i = 0; i < t; i++)
    {
        if (v - v2 > (t - i - 1) * d)
        {
            a *= -1;
            v = (t - i - 1) * d + v2;
        }
        distance += v;
        v += a * d;
    }
    printf("%d", distance);
    return 0;
}
