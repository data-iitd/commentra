#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Read an integer input which represents the number of elements

    int list[n]; // Create an array to hold the 1s and 0s
    int odd_count = 0; // Counter for odd numbers
    int odd_index = -1; // To store the index of the odd number

    // Read the elements and populate the list with 1 for odd and 0 for even
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        list[i] = x % 2; // 1 for odd, 0 for even
        if (list[i] == 1) {
            odd_count++;
            odd_index = i; // Store the index of the odd number
        }
    }

    // Check if there is exactly one odd number in the list
    if (odd_count == 1) {
        // If there is one odd number, print its position (1-based index)
        printf("%d\n", odd_index + 1);
    } else {
        // If there are no odd numbers, print the position of the first even number (1-based index)
        for (int i = 0; i < n; i++) {
            if (list[i] == 0) {
                printf("%d\n", i + 1);
                break;
            }
        }
    }

    return 0;
}
// <END-OF-CODE>
