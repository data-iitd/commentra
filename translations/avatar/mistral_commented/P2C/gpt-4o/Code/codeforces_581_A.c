#include <stdio.h>

int main() {
    int a, b;

    // Get user input
    scanf("%d %d", &a, &b);

    // Find the minimum value between 'a' and 'b'
    int min_value = (a < b) ? a : b;

    // Find the maximum value between 'a' and 'b'
    int max_value = (a > b) ? a : b;

    // Print the minimum value and the average of the difference between minimum and maximum values
    printf("%d %d\n", min_value, (max_value - min_value) / 2);

    return 0;
}
// <END-OF-CODE>
