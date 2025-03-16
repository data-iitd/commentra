
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    long N;
    scanf("%ld", &N);
    long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            scanf("%ld", &min);
        } else {
            long tmp;
            scanf("%ld", &tmp);
            if (tmp < min) {
                min = tmp;
            }
        }
    }
    printf("%ld\n", (long)ceil((double)N / min) + 4);
    return 0;
}
// END-OF-CODE