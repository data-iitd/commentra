

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the value of N
    long N;
    scanf("%ld", &N);

    // Initialize min to 0 and find the minimum of the first five inputs
    long min = 0;
    for (int i = 0; i < 5; i++) {
        if (i == 0) {
            scanf("%ld", &min);
        } else {
            long temp;
            scanf("%ld", &temp);
            if (temp < min) {
                min = temp;
            }
        }
    }

    // Calculate the result and print it
    printf("%ld\n", (long)ceil((double)N / min) + 4);

    return 0;
}

