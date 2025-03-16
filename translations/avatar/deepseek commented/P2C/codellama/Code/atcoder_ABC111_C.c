#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, j, k, l, m, x[100000], cnta[100002], cntb[100002], vala, vala1, maxCnta, maxCnta1, valb, valb1, maxCntb, maxCntb1, res, resa, resb, resa1, resb1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);

    // Split the list x into two lists, a and b, based on their indices (even and odd)
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            a[i] = x[i];
        else
            b[i] = x[i];
    }

    // Initialize two lists to count the frequency of each element in a and b
    for (i = 0; i < 100002; i++)
    {
        cnta[i] = 0;
        cntb[i] = 0;
    }

    // Find the most frequent element in list a and its first and second most frequent elements
    vala = 0;
    vala1 = 0;
    maxCnta = 0;
    maxCnta1 = 0;
    for (i = 0; i < n; i++)
    {
        cnta[a[i]] += 1;
        if (maxCnta < cnta[a[i]])
        {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (maxCnta1 < cnta[a[i]] && vala != a[i])
        {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Find the most frequent element in list b and its first and second most frequent elements
    valb = 0;
    valb1 = 0;
    maxCntb = 0;
    maxCntb1 = 0;
    for (i = 0; i < n; i++)
    {
        cntb[b[i]] += 1;
        if (maxCntb < cntb[b[i]])
        {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (maxCntb1 < cntb[b[i]] && valb != b[i])
        {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Compare the most frequent elements of a and b
    if (valb != vala)
    {
        res = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] != vala)
                res += 1;
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] != valb)
                res += 1;
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
                resa += 1;
            if (a[i] != vala1)
                resa1 += 1;
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] != valb)
                resb += 1;
            if (b[i] != valb1)
                resb1 += 1;
        }
        printf("%d", min(resa + resb1, resa1 + resb));
    }

    return 0;
}

