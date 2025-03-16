#include <stdio.h>
#include <string.h>

int main() {
    int n;  // Number of elements
    scanf("%d", &n);  // Take an integer input
    char q[n][100];  // Initialize a 2D array to store the elements (assuming max length of each string is 99)
    int count = 0;  // Initialize a counter to keep track of valid pairs

    // Loop to take input and store in the array `q`
    for (int i = 0; i < n; i++) {
        scanf("%s", q[i]);  // Read a string into the array
    }

    // Nested loop to compare each element with every other element
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            if (k == j) {  // Skip if the same element is compared with itself
                continue;
            } else if (q[j][0] == q[k][strlen(q[k]) - 1]) {  // Check if the first character of `q[j]` matches the last character of `q[k]`
                count++;  // Increment the counter if the condition is met
            }
        }
    }

    printf("%d\n", count);  // Print the total count of valid pairs
    return 0;
}  // <END-OF-CODE>
