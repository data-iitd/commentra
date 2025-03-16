#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, x[100000], a[100000], b[100000], cnta[100002], cntb[100002], vala, valb, maxCnta, maxCntb, vala1, valb1, maxCnta1, maxCntb1, resa, resb, resa1, resb1, res;

    // Take the number of elements in the list from user input
    scanf("%d", &n);

    // Initialize an empty list 'x' to store the input elements
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    // Initialize two empty lists 'a' and 'b' to store even and odd elements respectively
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

    // Initialize two lists 'cnta' and 'cntb' of size 100002+1 to store the count of each element in lists 'a' and 'b' respectively
    for (i = 0; i < 100002; i++)
    {
        cnta[i] = 0;
        cntb[i] = 0;
    }

    // Initialize two variables 'vala' and 'valb' to store the elements with maximum count in lists 'a' and 'b' respectively
    vala = 0;
    valb = 0;

    // Initialize two variables 'maxCnta' and 'maxCntb' to store the maximum count of an element in lists 'a' and 'b' respectively
    maxCnta = 0;
    maxCntb = 0;

    // Iterate through list 'a' and update the count of each element in 'cnta'
    for (i = 0; i < n; i++)
    {
        cnta[a[i]] += 1;
    }

    // Find the element with maximum count in list 'a' and update 'vala' and 'maxCnta'
    for (i = 0; i < n; i++)
    {
        if (maxCnta < cnta[a[i]])
        {
            vala = a[i];
            maxCnta = cnta[a[i]];
        }
    }

    // Find the second element with maximum count in list 'a' (different from 'vala') and update 'vala1' and 'maxCnta1'
    for (i = 0; i < n; i++)
    {
        if (maxCnta1 < cnta[a[i]] && a[i] != vala)
        {
            maxCnta1 = cnta[a[i]];
            vala1 = a[i];
        }
    }

    // Similar logic for list 'b'
    for (i = 0; i < n; i++)
    {
        cntb[b[i]] += 1;
    }

    // Find the element with maximum count in list 'b' and update 'valb' and 'maxCntb'
    for (i = 0; i < n; i++)
    {
        if (maxCntb < cntb[b[i]])
        {
            valb = b[i];
            maxCntb = cntb[b[i]];
        }
    }

    // Find the second element with maximum count in list 'b' (different from 'valb') and update 'valb1' and 'maxCntb1'
    for (i = 0; i < n; i++)
    {
        if (maxCntb1 < cntb[b[i]] && b[i] != valb)
        {
            maxCntb1 = cntb[b[i]];
            valb1 = b[i];
        }
    }

    // Check if 'vala' and 'valb' are same or not
    if (valb != vala)
    {
        // If they are not same, calculate the sum of counts of all elements except 'vala' and 'valb' and print the result
        res = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] != vala && b[i] != valb)
            {
                res += 1;
            }
        }
        printf("%d\n", res);
    }
    else
    {
        // If 'vala' and 'valb' are same, calculate the sum of counts of all elements except 'vala' and the second element with maximum count in list 'a' and list 'b' respectively
        // and print the minimum of these two sums
        resa = 0;
        resb = 0;
        resa1 = 0;
        resb1 = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] != vala)
            {
                resa += 1;
            }
            if (a[i] != vala1)
            {
                resa1 += 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (b[i] != valb)
            {
                resb += 1;
            }
            if (b[i] != valb1)
            {
                resb1 += 1;
            }
        }
        printf("%d\n", min(resa + resb1, resa1 + resb));
    }

    return 0;
}

