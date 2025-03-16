
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAX 1000000000000000000

int main()
{
    long min = MAX;
    long a[4];
    char op[3];
    int i, j, k;
    for(i = 0; i < 4; i++)
    {
        scanf("%ld", &a[i]);
    }
    for(i = 0; i < 3; i++)
    {
        scanf("%s", op[i]);
    }
    for(i = 0; i < 4; i++)
    {
        for(j = i + 1; j < 4; j++)
        {
            for(k = 0; k < 4; k++)
            {
                if(k!= j && k!= i)
                {
                    printf("%ld ", a[k]);
                }
            }
            if(op[0] == '+')
            {
                printf("%ld\n", a[i] + a[j]);
            }
            else
            {
                printf("%ld\n", a[i] * a[j]);
            }
            fflush(stdout);
            long res;
            if(op[0] == '+')
            {
                res = a[i] + a[j];
            }
            else
            {
                res = a[i] * a[j];
            }
            long temp[3];
            temp[0] = a[0];
            temp[1] = a[1];
            temp[2] = res;
            int l;
            for(l = 0; l < 3; l++)
            {
                a[l] = temp[l];
            }
            util(a, op, 1);
        }
    }
    printf("%ld\n", min);
    return 0;
}

void util(long a[4], char op[3], int idx)
{
    if(idx == 3)
    {
        min = min < a[0]? min : a[0];
        return;
    }
    for(i = 0; i < 4; i++)
    {
        for(j = i + 1; j < 4; j++)
        {
            long temp[3];
            temp[0] = a[0];
            temp[1] = a[1];
            if(op[idx] == '+')
            {
                temp[2] = a[i] + a[j];
            }
            else
            {
                temp[2] = a[i] * a[j];
            }
            int l;
            for(l = 0; l < 3; l++)
            {
                a[l] = temp[l];
            }
            util(a, op, idx + 1);
        }
    }
}

