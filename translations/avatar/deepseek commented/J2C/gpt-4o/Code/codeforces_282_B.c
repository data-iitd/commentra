#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n); // Read the number of elements
    char ch[n]; // Declare a character array to store the result
    int s1 = 0, s2 = 0; // Initialize sums for two paths
    int flag = 0, j = 0; // Declare loop variables and a flag for invalid configuration

    // Loop to read inputs and decide paths
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y); // Read the next integers for path 'x' and 'y'
        int temp1 = s1 + x; // Calculate temporary sum for path 'x'
        int temp2 = s2 + y; // Calculate temporary sum for path 'y'

        // Check if adding to path 'x' or 'y' is valid
        if (abs(temp1 - s2) <= 500) {
            s1 += x; // Update sum for path 'x'
            ch[j++] = 'A'; // Append 'A' to the result array
            continue; // Continue to the next iteration
        }
        if (abs(temp2 - s1) <= 500) {
            s2 += y; // Update sum for path 'y'
            ch[j++] = 'G'; // Append 'G' to the result array
            continue; // Continue to the next iteration
        }
        flag = 1; // Set flag to indicate invalid configuration
        break; // Break out of the loop
    }

    // Handle the result based on the flag
    if (flag == 1) {
        printf("-1\n"); // Print -1 if configuration is invalid
    } else {
        ch[j] = '\0'; // Null-terminate the string
        printf("%s\n", ch); // Print the result string
    }

    return 0;
}
