#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", 360 / gcd(360, x));
    return 0;
}
