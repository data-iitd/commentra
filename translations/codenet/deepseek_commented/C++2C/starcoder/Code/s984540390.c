#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>
#include <limits.h>
#include <assert.h>

int main() {
    // Input the value of h
    int h;
    scanf("%d", &h);

    // Loop to calculate the answer
    while (h!= 1) {
        if (h % 2!= 0) {
            h--; // Decrement h if it is odd
        }
        h /= 2; // Divide h by 2
        cnt *= 2; // Double the count
        ans += cnt; // Increment the sum by the current count
    }

    // Output the final result
    printf("%d\n", ans + 1);
}

