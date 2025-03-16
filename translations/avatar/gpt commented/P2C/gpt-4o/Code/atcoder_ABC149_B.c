#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    
    // Read a line of input and split it into parts
    for (int i = 0; i < 3; i++) {
        scanf("%d", &cookies[i]);
    }

    // Calculate the leftover cookies after taking some from the third type
    int leftOver = cookies[0] - cookies[2];

    // Determine the number of cookies Takahashi can take, ensuring it's not negative
    int takahashi = leftOver > 0 ? leftOver : 0;

    // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
    if (takahashi > 0) {
        printf("%d %d\n", takahashi, cookies[1]);
    } else {
        printf("%d %d\n", takahashi, (cookies[1] - abs(leftOver) > 0) ? (cookies[1] - abs(leftOver)) : 0);
    }

    return 0;
}

// <END-OF-CODE>
