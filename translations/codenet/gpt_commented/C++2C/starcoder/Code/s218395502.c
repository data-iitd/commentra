#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare three integer variables to hold the input values
    int a, b, c;

    // Read three integers from the user input
    scanf("%d %d %d", &a, &b, &c);

    // Check if the number formed by a, b, and c is divisible by 4
    // The number is formed as 100*a + 10*b + c
    if ((100 * a + 10 * b + c) % 4 == 0) {
        // If the number is divisible by 4, output "YES"
        printf("YES\n");
    }
    else {
        // If the number is not divisible by 4, output "NO"
        printf("NO\n");
    }
}
