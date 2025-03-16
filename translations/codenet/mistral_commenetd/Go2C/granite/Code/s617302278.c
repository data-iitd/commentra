
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    // Reading integers from stdin as a line text
    char buf[1024];
    fgets(buf, sizeof(buf), stdin);
    char *endptr;
    int x = strtol(buf, &endptr, 10);

    // Initializing sum variable as zero
    int sum = 0;
    // Initializing index variable as one
    int i = 1;
    // Looping until the sum is greater than or equal to x
    while (sum < x) {
        // Adding current index to sum
        sum += i;
        // Incrementing index
        i++;
    }
    // Printing the index
    printf("%d\n", i);

    return 0;
}
