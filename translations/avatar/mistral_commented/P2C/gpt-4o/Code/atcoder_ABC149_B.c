#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    
    // Read input values into the cookies array
    for (int i = 0; i < 3; i++) {
        scanf("%d", &cookies[i]);
    }

    // Calculate the difference between the number of cookies given to the first and second child
    int leftOver = cookies[0] - cookies[2];

    // Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
    int takahashi = (leftOver > 0) ? leftOver : 0;

    // Print the result using string concatenation
    if (takahashi > 0) {
        printf("%d %d\n", takahashi, cookies[1]);
    } else {
        printf("%d %d\n", takahashi, (cookies[1] - abs(leftOver) > 0) ? (cookies[1] - abs(leftOver)) : 0);
    }

    return 0;
}

// <END-OF-CODE>
