#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, x[100002], a[100002], b[100002], cnta[100002], cntb[100002], vala, vala1, maxCnta, maxCnta1, valb, valb1, maxCntb, maxCntb1, res, resa, resb, resa1, resb1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a[i] = x[i];
        }
        else
        {
            b[i] = x[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        cnta[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cntb[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cnta[a[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        cntb[b[i]]++;
    }
    for (i = 0; i < n; i++)
    {
        if (maxCnta < cnta[i])
        {
            vala = i;
            maxCnta = cnta[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (maxCnta1 < cnta[i] && vala != i)
        {
            maxCnta1 = cnta[i];
            vala1 = i;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (maxCntb < cntb[i])
        {
            valb = i;
            maxCntb = cntb[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (maxCntb1 < cntb[i] && valb != i)
        {
            maxCntb1 = cntb[i];
            valb1 = i;
        }
    }
    if (valb != vala)
    {
        res = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] != vala)
            {
                res++;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] != valb)
            {
                res++;
            }
        }
        printf("%d", res);
    }
    else
    {
        resa = 0;
        resb = 0;
        resa1 = 0;
        resb1 = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] != vala)
            {
                resa++;
            }
            if (a[i] != vala1)
            {
                resa1++;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] != valb)
            {
                resb++;
            }
            if (b[i] != valb1)
            {
                resb1++;
            }
        }
        printf("%d", min(resa + resb1, resa1 + resb));
    }
    return 0;
}