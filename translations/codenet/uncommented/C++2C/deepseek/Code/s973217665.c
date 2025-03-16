#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int p, q;
        scanf("%d %d", &p, &q);
        int l = (int)sqrt(p * p + q * q);
        bool isprime = true;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                int x = i * i + j * j;
                if (x <= 1 || x >= p * p + q * q) continue;
                if ((i * p + j * q) % x == 0 && (i * q - j * p) % x == 0) isprime = false;
            }
        }
        printf("%s\n", isprime ? "P" : "C");
    }
    return 0;
}
