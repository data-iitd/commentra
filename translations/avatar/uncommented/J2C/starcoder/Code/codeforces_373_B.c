#include <stdio.h>
#include <stdlib.h>

int main() {
    long gen, st, tim;
    scanf("%ld %ld %ld", &gen, &st, &tim);
    gen /= tim;
    long beg = st - 1, end = (long) pow(10, 18);
    while (true) {
        long med = (beg + end) / 2 + 1;
        if (get(med) - get(st - 1) > gen) {
            end = med - 1;
        } else {
            beg = med;
        }
        if (beg == end) {
            printf("%ld\n", beg - st + 1);
            break;
        }
    }
    return 0;
}

