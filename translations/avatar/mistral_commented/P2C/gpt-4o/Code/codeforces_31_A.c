#include <stdio.h>

int main() {
    int y;
    scanf("%d", &y); // Take an integer input from the user

    int arr[100]; // Assuming a maximum size of 100 for the array
    for (int i = 0; i < y; i++) {
        scanf("%d", &arr[i]); // Take a list of integers as input from the user
    }

    // Iterate through each index 'i' in the list 'arr'
    for (int i = 0; i < y; i++) {
        // Iterate through each index 'j' in the list 'arr' (excluding the current index 'i')
        for (int j = 0; j < y; j++) {
            // Check if the current indices 'i' and 'j' are equal, if yes then skip the current iteration
            if (i == j) {
                continue;
            }
            // Iterate through each index 'k' in the list 'arr' (excluding the indices 'i' and 'j')
            for (int k = 0; k < y; k++) {
                // Check if the current indices 'i', 'j' and 'k' satisfy the given condition
                if (arr[k] != arr[j] && arr[k] != arr[i] && arr[k] == arr[i] + arr[j]) {
                    // If the condition is true, print the indices 'i', 'j' and 'k' and exit the function
                    printf("%d %d %d\n", k + 1, j + 1, i + 1);
                    return 0;
                }
            }
        }
    }
    // If no such indices are found, print -1
    printf("-1\n");
    return 0;
}
// <END-OF-CODE>
