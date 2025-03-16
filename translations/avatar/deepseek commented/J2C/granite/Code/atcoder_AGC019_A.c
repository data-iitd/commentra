
#include <stdio.h>

int main() {
    long long Q, H, S, D, N;
    scanf("%lld %lld %lld %lld %lld", &Q, &H, &S, &D, &N);

    long long onePrice = (Q * 4 < H * 2)? (Q * 4 < S)? Q * 4 : S : (H * 2 < S)? H * 2 : S;

    if ((double)onePrice <= (double)D / 2) {
        printf("%lld\n", onePrice * N);
    } else {
        printf("%lld\n", (N / 2) * D + (N % 2) * onePrice);
    }

    return 0;
}
