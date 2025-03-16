#include <stdio.h>

int main() {
    int n, i, j;

    // Taking an integer input from the user
    scanf("%d", &n);

    // Initializing variables i and j
    i = 1;
    j = n * n;

    // Starting a while loop that continues as long as i is less than j
    while (i < j) {
        printf("%d %d\n", i, j);  // Printing the current values of i and j
        i += 1;       // Incrementing i by 1
        j -= 1;       // Decrementing j by 1
    }

    return 0;
}
