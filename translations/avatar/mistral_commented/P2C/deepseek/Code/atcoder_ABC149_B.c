#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    int leftOver;
    int takahashi;

    // Read the input values into the 'cookies' array
    for (int i = 0; i < 3; i++) {
        scanf("%d", &cookies[i]);
    }

    // Calculate the difference between the number of cookies given to the first and second child
    leftOver = cookies[0] - cookies[2];

    // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
    takahashi = (leftOver > 0) ? leftOver : 0;

    // Print the result using string concatenation
    printf("%d %d\n", takahashi, (leftOver > 0) ? cookies[1] : (cookies[1] - abs(leftOver) > 0) ? cookies[1] - abs(leftOver) : 0);

    return 0;
}
