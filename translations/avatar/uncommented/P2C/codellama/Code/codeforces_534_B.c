
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char v1[100], v2[100], t[100], d[100];
    int v1_int, v2_int, t_int, d_int, a, v, distance;
    scanf("%s %s", v1, v2);
    scanf("%s %s", t, d);
    v1_int = atoi(v1);
    v2_int = atoi(v2);
    t_int = atoi(t);
    d_int = atoi(d);
    a = 1;
    v = v1_int;
    distance = 0;
    for (int i = 0; i < t_int; i++)
    {
        if (v - v2_int > (t_int - i - 1) * d_int)
        {
            a *= -1;
            v = (t_int - i - 1) * d_int + v2_int;
        }
        distance += v;
        v += a * d_int;
    }
    printf("%d", distance);
    return 0;
}

