#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p[2], q[2], vec[2], tmp;
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &q[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        vec[i] = p[i] - q[i];
    }
    tmp = vec[0];
    vec[0] = vec[1];
    vec[1] = -tmp;
    int newpos[2];
    for (int i = 0; i < 2; i++)
    {
        newpos[i] = q[i] + vec[i];
    }
    for (int i = 0; i < 2; i++)
    {
        printf("%d ", newpos[i]);
    }
    return 0;
}
