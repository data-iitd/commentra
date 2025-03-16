#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, res, resa, resb, resa1, resb1, vala, vala1, valb, valb1, maxCnta, maxCnta1, maxCntb, maxCntb1;
    scanf("%d", &n);
    int *x = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    int *a = (int *)malloc(n * sizeof(int));
    int *b = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            a[i] = x[i];
        else
            b[i] = x[i];
    }
    int *cnta = (int *)malloc((100002 + 1) * sizeof(int));
    int *cntb = (int *)malloc((100002 + 1) * sizeof(int));
    for (i = 0; i < 100002 + 1; i++)
    {
        cnta[i] = 0;
        cntb[i] = 0;
    }
    for (i = 0; i < n; i++)
        cnta[a[i]]++;
    for (i = 0; i < n; i++)
        cntb[b[i]]++;
    vala = 0;
    maxCnta = 0;
    for (i = 0; i < 100002 + 1; i++)
    {
        if (maxCnta < cnta[i])
        {
            vala = i;
            maxCnta = cnta[i];
        }
    }
    vala1 = 0;
    maxCnta1 = 0;
    for (i = 0; i < 100002 + 1; i++)
    {
        if (maxCnta1 < cnta[i] && vala!= i)
        {
            maxCnta1 = cnta[i];
            vala1 = i;
        }
    }
    valb = 0;
    maxCntb = 0;
    for (i = 0; i < 100002 + 1; i++)
    {
        if (maxCntb < cntb[i])
        {
            valb = i;
            maxCntb = cntb[i];
        }
    }
    valb1 = 0;
    maxCntb1 = 0;
    for (i = 0; i < 100002 + 1; i++)
    {
        if (maxCntb1 < cntb[i] && valb!= i)
        {
            maxCntb1 = cntb[i];
            valb1 = i;
        }
    }
    if (valb!= vala)
    {
        res = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i]!= vala)
                res++;
        }
        for (i = 0; i < n; i++)
        {
            if (b[i]!= valb)
                res++;
        }
        printf("%d\n", res);
    }
    else
    {
        resa = 0;
        resb = 0;
        resa1 = 0;
        resb1 = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i]!= vala)
                resa++;
            if (a[i]!= vala1)
                resa1++;
        }
        for (i = 0; i < n; i++)
        {
            if (b[i]!= valb)
                resb++;
            if (b[i]!= valb1)
                resb1++;
        }
        printf("%d\n", min(resa + resb1, resa1 + resb));
    }
    return 0;
}

