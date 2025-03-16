#include <stdio.h>

int main() {
    // Declare two integer variables S and W
    int S, W;

    // Get the input as two integers
    scanf("%d %d", &S, &W);

    // Check if the condition S <= W is true or false and print the corresponding message
    if (S <= W) {
        printf("unsafe\n");
    } else {
        printf("safe\n");
    }

    return 0;
}

// <END-OF-CODE>
