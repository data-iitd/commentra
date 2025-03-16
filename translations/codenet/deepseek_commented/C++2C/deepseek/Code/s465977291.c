#include <stdio.h>
#include <math.h>

int main() {
    int n, d;
    scanf("%d %d", &n, &d);

    double a = d * 2 + 1;
    printf("%d\n", (int)ceil(n / a));

    return 0;
}
