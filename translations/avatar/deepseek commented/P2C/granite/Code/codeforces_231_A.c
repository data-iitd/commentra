
#include <stdio.h>

int main() {
    // Take an integer input `n` which represents the number of lists to be provided as input.
    int n;
    scanf("%d", &n);

    // Initialize a counter `c` to 0. This will keep track of the number of lists where the sum of elements is greater than 1.
    int c = 0;

    // Loop `n` times to process each list of integers.
    for (int i = 0; i < n; i++) {
        // Take a list of integers as input, split them by spaces, convert them to integers, and store them in `l1`.
        int l1[100];
        for (int j = 0; j < 100; j++) {
            scanf("%d", &l1[j]);
        }
        
        // Calculate the sum of the elements in `l1`.
        // If the sum is greater than 1, increment the counter `c` by 1.
        int sum = 0;
        for (int j = 0; j < 100; j++) {
            sum += l1[j];
        }
        if (sum > 1) {
            c++;
        }
    }

    // After the loop completes, print the final value of `c`, which represents the number of lists where the sum of elements is greater than 1.
    printf("%d", c);

    return 0;
}
