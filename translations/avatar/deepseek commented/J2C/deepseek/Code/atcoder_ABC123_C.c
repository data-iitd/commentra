#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long N;
    scanf("%ld", &N);

    long min = 0;
    long temp;
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            scanf("%ld", &min);
        } else {
            scanf("%ld", &temp);
            if (temp < min) {
                min = temp;
            }
        }
    }

    long result = (long)ceil((double)N / min) + 4;
    printf("%ld\n", result);

    return 0;
}
