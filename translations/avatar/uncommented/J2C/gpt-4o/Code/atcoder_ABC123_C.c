#include <stdio.h>
#include <math.h>

void printLong(long ans) {
    printf("%ld\n", ans);
}

int main() {
    long N;
    scanf("%ld", &N);
    
    long min = 0;
    for (int i = 0; i < 5; i++) {
        long current;
        scanf("%ld", &current);
        if (i == 0) {
            min = current;
        } else {
            if (current < min) {
                min = current;
            }
        }
    }
    
    printLong((long)ceil((double)N / min) + 4);
    
    return 0;
}
