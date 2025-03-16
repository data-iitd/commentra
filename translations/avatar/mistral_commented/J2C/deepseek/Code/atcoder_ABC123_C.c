#include <stdio.h>
#include <math.h>

int main() {
    long N;
    long min;
    long temp;

    // Reading the first long integer input N
    scanf("%ld", &N);

    // Initializing the minimum long integer variable with the first input value
    scanf("%ld", &min);
    for (int i = 1; i < 5; i++) {
        scanf("%ld", &temp);
        if (temp < min) {
            min = temp;
        }
    }

    // Printing the answer
    printf("%ld\n", (long)ceil((double)N / min) + 4);

    return 0;
}

