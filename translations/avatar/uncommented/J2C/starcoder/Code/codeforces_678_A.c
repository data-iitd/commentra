#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, z;
    scanf("%d %d", &n, &k);
    n++;
    if (n % k!= 0)
        z = k - n % k;
    else
        z = 0;
    printf("%d\n", n + z);
    return 0;
}
