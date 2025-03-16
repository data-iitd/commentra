#include <stdio.h>
#include <math.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    double a = d * 2 + 1;
    printf("%lld\n", (long long)ceil(n / a));

    return 0;
}

// <END-OF-CODE>
