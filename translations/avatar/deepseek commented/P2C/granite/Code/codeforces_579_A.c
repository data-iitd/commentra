

#include <math.h>
#include <stdio.h>

int main() {
    int n, x = 1;
    scanf("%d", &n);
    while (log2(n)!= (int)log2(n)) {
        x++;
        n -= pow(2, (int)log2(n));
    }
    printf("%d\n", x);
    return 0;
}
