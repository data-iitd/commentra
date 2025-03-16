#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    long long a,b;
    scanf("%lld %lld",&a,&b);
    printf("%lld\n",max(a+b,max(a-b,a*b)));

    return 0;
}

