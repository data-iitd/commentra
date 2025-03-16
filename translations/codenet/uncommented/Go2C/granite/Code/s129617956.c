
#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int rt = sqrt(n);
    int minf = 100;
    for (int i = 1; i < rt + 1; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = fmin(minf, ndigit);
        }
    }
    printf("%d\n", minf);
    return 0;
}

// 