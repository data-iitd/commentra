
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int max_val = (x + y - 3 + ((y - x) % 3 > 0)) > 0 ? (x + y - 3 + ((y - x) % 3 > 0)) : 0;

    printf("%d", max_val);

    return 0;
}

