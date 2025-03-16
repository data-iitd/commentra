
#include <stdio.h>

int main() {
long Q, H, S, D, N;
scanf("%ld %ld %ld %ld %ld", &Q, &H, &S, &D, &N);
long onePrice = (Q * 4 < H * 2)? ((Q * 4 < S)? (Q * 4) : (S)) : ((H * 2 < S)? (H * 2) : (S));
if ((double)onePrice <= (double)D / 2) {
printf("%ld\n", N * onePrice);
} else {
printf("%ld\n", (N / 2) * D + (N % 2) * onePrice);
}
return 0;
}

// END-OF-CODE


