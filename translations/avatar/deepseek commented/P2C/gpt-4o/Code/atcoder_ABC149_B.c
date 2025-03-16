#include <stdio.h>

int main() {
    int cookies[3];  // Array to hold the cookie counts
    for (int i = 0; i < 3; i++) {
        scanf("%d", &cookies[i]);  // Taking input from the user
    }

    int leftOver = cookies[0] - cookies[2];  // Calculating the difference between the first and third elements
    int takahashi = leftOver > 0 ? leftOver : 0;  // Calculating the number of cookies Takahashi gets, ensuring it's not negative

    // Printing the result
    if (takahashi > 0) {
        printf("%d %d\n", takahashi, cookies[1]);
    } else {
        printf("%d %d\n", takahashi, cookies[1] > abs(leftOver) ? cookies[1] - abs(leftOver) : 0);
    }

    return 0;
}
// <END-OF-CODE>
