#include <stdio.h>
#include <stdlib.h>

int main() {
    int cookies[3];
    int leftOver, takahashi;

    // Read a line of input, split it into parts, and convert each part to an integer
    scanf("%d %d %d", &cookies[0], &cookies[1], &cookies[2]);

    // Calculate the leftover cookies after taking some from the third type
    leftOver = cookies[0] - cookies[2];

    // Determine the number of cookies Takahashi can take, ensuring it's not negative
    takahashi = (leftOver > 0) ? leftOver : 0;

    // Print the number of cookies Takahashi can take, and the remaining cookies of the second type
    // If Takahashi can take cookies, print the second type's count; otherwise, calculate the remaining
    printf("%d %d\n", takahashi, (takahashi > 0) ? cookies[1] : (cookies[1] > abs(leftOver)) ? cookies[1] - abs(leftOver) : 0);

    return 0;
}
