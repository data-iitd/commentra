

#include <stdio.h>

int main() {
    int n, count = 0;
    scanf("%d", &n);  // Take an integer input representing the number of elements
    char q[n][100];  // Declare a 2D array to store the elements

    // Loop to take input and store in the 2D array `q`
    for (int i = 0; i < n; i++) {
        scanf("%s", q[i]);  // Read a string input and store in `q[i]`
    }

    // Nested loop to compare each element with every other element
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (k == j) {  // Skip if the same element is compared with itself
                continue;
            } else if (q[j][0] == q[k][strlen(q[k]) - 1]) {  // Check if the first character of `q[j]` matches the last character of `q[k]`
                count++;  // Increment the counter if the condition is met
            } else {
                continue;
            }
        }
    }

    printf("%d", count);  // Print the total count of valid pairs

    return 0;
}
