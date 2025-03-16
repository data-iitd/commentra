#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    long N;
    long min;
    long temp;
    int i;

    scanf("%ld", &N);
    min = 0;
    for (i = 0; i < 5; i++) {
        if (i == 0) {
            scanf("%ld", &min);
        } else {
            scanf("%ld", &temp);
            if (temp < min) {
                min = temp;
            }
        }
    }
    printf("%ld\n", (long)ceil((double)N / min) + 4);
    return 0;
}

