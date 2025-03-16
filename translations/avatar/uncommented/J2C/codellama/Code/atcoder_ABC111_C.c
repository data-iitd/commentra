
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    int v[100010];
    int vo[100010];
    int ve[100010];
    int vt[100010];
    memset(vo, 0, sizeof(vo));
    memset(ve, 0, sizeof(ve));
    memset(vt, 0, sizeof(vt));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        vt[v[i]]++;
        if (i % 2 == 0)
        {
            ve[v[i]]++;
        }
        else
        {
            vo[v[i]]++;
        }
    }
    qsort(vo, 100010, sizeof(int), cmp);
    qsort(ve, 100010, sizeof(int), cmp);
    qsort(vt, 100010, sizeof(int), cmp);
    int ans = 0;
    if (vo[0] + ve[0] == vt[0])
    {
        ans = min(n - vo[0] - ve[1], n - vo[1] - ve[0]);
    }
    else
    {
        ans = n - vo[0] - ve[0];
    }
    printf("%d\n", ans);
    return 0;
}

int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

