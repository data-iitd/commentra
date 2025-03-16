
#include <stdio.h>
#include <math.h>

int main()
{
    int n, x = 1;
    printf("Enter an integer: ");
    scanf("%d", &n);
    while (log2(n) % 1)
    {
        x++;
        n -= pow(2, (int)log2(n));
    }
    printf("The value of x is %d\n", x);
    return 0;
}

