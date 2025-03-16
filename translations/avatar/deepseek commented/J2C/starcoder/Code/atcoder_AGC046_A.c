
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, count, tmp;
    scanf("%d", &x);
    count = 0;
    tmp = x;
    x = 0;
    while(x!= 360)
    {
        x = x + tmp;
        if(x > 360)
            x = x - 360;
        count++;
    }
    printf("%d", count);
    return 0;
}

