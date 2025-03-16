#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, a[100002], b[100002], cnta[100002], cntb[100002], vala, valb, vala1, valb1, maxCnta, maxCntb, maxCnta1, maxCntb1, resa, resb, resa1, resb1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < 100002; i++)
        cnta[i] = 0;
    for (i = 0; i < 100002; i++)
        cntb[i] = 0;
    for (i = 0; i < n; i++)
        cnta[a[i]]++;
    for (i = 0; i < n; i++)
        cntb[b[i]]++;
    vala = 0;
    valb = 0;
    maxCnta = 0;
    maxCntb = 0;
    for (i = 0; i < 100002; i++)
    {
        if (maxCnta < cnta[i])
        {
            vala = i;
            maxCnta = cnta[i];
        }
    }
    for (i = 0; i < 100002; i++)
    {
        if (maxCnta1 < cnta[i] && i!= vala)
        {
            maxCnta1 = cnta[i];
            vala1 = i;
        }
    }
    for (i = 0; i < 100002; i++)
    {
        if (maxCntb < cntb[i])
        {
            valb = i;
            maxCntb = cntb[i];
        }
    }
    for (i = 0; i < 100002; i++)
    {
        if (maxCntb1 < cntb[i] && i!= valb)
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

