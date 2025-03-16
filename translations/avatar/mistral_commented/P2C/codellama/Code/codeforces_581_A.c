#include <stdio.h>

int main()
{
    int a, b, min_value, max_value;

    // Get user input as a list of strings, split by space character, and convert each to an integer
    scanf("%d %d", &a, &b);

    // Find the minimum value between 'a' and 'b'
    min_value = a < b ? a : b;

    // Find the maximum value between 'a' and 'b'
    max_value = a > b ? a : b;

    // Print the minimum value and the average of the difference between minimum and maximum values
    printf("%d %d\n", min_value, (max_value - min_value) / 2);

    return 0;
}

