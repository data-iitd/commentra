#include <stdio.h>

int main()
{
    int A, B, ans;

    // Read two integers from the user, separated by a space
    scanf("%d %d", &A, &B);

    // Calculate the difference between A and 2 times B
    ans = A - 2 * B;

    // Check if the difference is negative
    if (ans < 0)
    {
        // If it is, set it to zero
        ans = 0;
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}

