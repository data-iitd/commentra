#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    int leftOver, takahashi;

    // Taking input from the user and converting it into an array of integers
    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);

    // Calculating the difference between the first and third elements of the array
    leftOver = cookies[0] - cookies[2];

    // Calculating the number of cookies Takahashi gets, ensuring it's not negative
    takahashi = (leftOver > 0) ? leftOver : 0;

    // Printing the result, including the number of cookies Takahashi gets and the number of cookies left for Aoki
    if (takahashi > 0) {
        printf("%d %d\n", takahashi, cookies[1]);
    } else {
        printf("%d %d\n", 0, (cookies[1] > abs(leftOver)) ? cookies[1] - abs(leftOver) : 0);
    }

    return 0;
}
