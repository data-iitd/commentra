#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a, b, x;
    scanf("%lld%lld%lld", &a, &b, &x);
    long long int s = (b / x - a / x);
    if (a % x == 0) s++;
    printf("%lld\n", s);
    return 0;
}

// <END-OF-CODE>
