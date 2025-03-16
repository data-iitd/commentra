
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Read the number of test cases
    int n;
    scanf("%d", &n);

    // Initialize an array 'w' to store the occurrences of numbers
    int w[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    // Initialize a counter 'c' to store the result
    int c = 0;

    // Iterate through each number 'i' in the array 'w'
    for (int i = 0; i < n; i++) {
        // If the number 'i' is zero, then add its occurrences multiplied by (its occurrences - 1) to the counter 'c'
        if (w[i] == 0) {
            c += (count(w, w + n, 0) - 1);
        }
        // If the number '-i' is present in the array 'w', then add its occurrences multiplied by the occurrences of 'i' to the counter 'c'
        else if (count(w, w + n, -w[i]) > 0) {
            c += count(w, w + n, w[i]) * count(w, w + n, -w[i]);
        }
    }

    // Print the result divided by 2
    printf("%d\n", c / 2);

    return 0;
}
