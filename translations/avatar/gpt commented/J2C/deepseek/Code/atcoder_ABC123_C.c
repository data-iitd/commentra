#include <stdio.h>
#include <math.h>

int main() {
    long N;
    long min;
    long temp;
    int i;

    // Read a long integer N from user input
    scanf("%ld", &N);

    // Initialize a variable to hold the minimum value
    scanf("%ld", &min);

    // Loop to read four more long integers and find the minimum
    for (i = 1; i < 5; i++) {
        scanf("%ld", &temp);
        if (temp < min) {
            min = temp;
        }
    }

    // Calculate the result by dividing N by min, rounding up, and adding 4
    long result = (long) ceil((double) N / min) + 4;
    printf("%ld\n", result);

    return 0;
}
