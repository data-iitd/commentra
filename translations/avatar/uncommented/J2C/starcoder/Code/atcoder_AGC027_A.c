#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    int N, num;
    long x;
    scanf("%d", &N);
    scanf("%ld", &x);
    long sweet[N];
    for(int i = 0; i < N; i++)
    {
        scanf("%ld", &sweet[i]);
    }
    qsort(sweet, N, sizeof(long), compare);
    num = 0;
    for(int i = 0; i < N; i++)
    {
        if(x - sweet[num] >= 0)
        {
            x = x - sweet[num];
            num++;
        }
        else
        {
            break;
        }
    }
    if((num == N) && (x > 0))
    {
        num--;
    }
    printf("%d", num);
    return 0;
}

