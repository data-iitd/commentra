
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long N;
    long min;
    int i;
    scanf("%ld", &N);
    min = 0;
    for (i = 0; i < 5; i++)
    {
        if (i == 0)
            scanf("%ld", &min);
        else
            min = min < sc.nextLong() ? min : sc.nextLong();
    }
    printf("%ld\n", (long)ceil((double)N / min) + 4);
    return 0;
}

