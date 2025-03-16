

#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);  // Taking an integer input from the user
    i = 1; j = n * n;  // Initializing variables i and j

    // Starting a while loop that continues as long as i is less than j
    while (i < j) {
        printf("%d %d\n", i, j);  // Printing the current values of i and j
        i++;                       // Incrementing i by 1
        j--;                       // Decrementing j by 1
    }

    return 0;
}
