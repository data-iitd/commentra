#include <stdio.h>

int main() {
    long Q, H, S, D, N;
    scanf("%ld %ld %ld %ld %ld", &Q, &H, &S, &D, &N);

    long onePrice = (Q < H ? (Q < S ? Q : S) : (H < S ? H : S));
    onePrice = onePrice < (S / 2) ? onePrice : (S / 2);

    if ((double)onePrice <= (double)D / 2) {
        printf("%ld\n", N * onePrice);
    } else {
        printf("%ld\n", (N / 2) * D + (N % 2) * onePrice);
    }

    return 0;
}
