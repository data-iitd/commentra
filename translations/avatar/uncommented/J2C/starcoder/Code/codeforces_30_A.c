#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int A, B, n;
    scanf("%d %d %d", &A, &B, &n);
    if (A == 0)
    {
        if (B == 0)
            printf("1");
        else
            printf("No solution");
        return 0;
    }
    if (B % A!= 0)
    {
        printf("No solution");
        return 0;
    }
    B /= A;
    int neg = B < 0;
    if (neg && n % 2 == 0)
    {
        printf("No solution");
        return 0;
    }
    if (neg)
        B = -B;
    for (int x = 0; x <= B; x++)
    {
        if (pow(x, n) == B)
        {
            printf(neg? "-%d" : "%d", x);
            return 0;
        }
    }
    printf("No solution");
    return 0;
}

