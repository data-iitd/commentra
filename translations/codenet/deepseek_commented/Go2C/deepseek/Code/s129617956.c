#include <stdio.h>
#include <math.h>
#include <string.h>

int min(int i, int j) {
    return i < j ? i : j;
}

int nextInt() {
    int n;
    scanf("%d", &n);
    return n;
}

int main() {
    int n = nextInt();
    int rt = (int)sqrt(n);
    int minf = 100;

    for (int i = 1; i <= rt + 1; i++) {
        if (n % i == 0) {
            int b = n / i;
            int ndigit = 0;
            while (b > 0) {
                b /= 10;
                ndigit++;
            }
            minf = min(minf, ndigit);
        }
    }

    printf("%d\n", minf);
    return 0;
}

