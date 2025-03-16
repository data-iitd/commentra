
#include <stdio.h>

int main() {
    int n, i, odd_count = 0, even_count = 0, odd_index = -1, even_index = -1;

    // Read an integer input which represents the number of elements
    scanf("%d", &n);

    // Read a line of input, split it into individual elements, convert them to integers,
    // and create a list that contains 1 for odd numbers and 0 for even numbers
    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0) {
            even_count++;
            even_index = i;
        } else {
            odd_count++;
            odd_index = i;
        }
    }

    // Check if there is exactly one odd number in the list
    if (odd_count == 1) {
        // If there is one odd number, print its position (1-based index)
        printf("%d\n", odd_index + 1);
    } else {
        // If there are no odd numbers, print the position of the first even number (1-based index)
        printf("%d\n", even_index + 1);
    }

    return 0;
}
