#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Read the size of the island (n) and the number of 'L' characters (count) from the input
    int n, count;
    scanf("%d %d", &n, &count);
    
    // Call the method to print the island pattern based on the input values
    printIsland(n, count);
    
    return 0;
}

void printIsland(int n, int count) {
    // Calculate the number of 'L' and 'S' characters that can be placed on the island
    int a = (n + 1) / 2; // Number of 'L' characters in the first half
    int b = n / 2;       // Number of 'L' characters in the second half
    int max = a * a + b * b; // Maximum number of 'L' characters that can fit in the island
    
    // Check if the provided count exceeds the maximum possible 'L' characters
    if (count > max) {
        printf("NO"); // Print "NO" if the count is too high
        return; // Exit the method
    }
    
    // If the count is valid, print "YES"
    printf("YES");
    
    // Loop through each row of the island
    for (int i = 0; i < n; i++) {
        char *sb = (char *) malloc(n * sizeof(char)); // Create a char array to construct the row
        
        // Loop through each column of the island
        for (int j = 0; j < n; j++) {
            // Place 'L' if the sum of indices is even and there are still 'L' characters left
            if ((i + j) % 2 == 0 && count > 0) {
                sb[j] = 'L'; // Append 'L' to the current row
                count--; // Decrement the count of 'L' characters
            } else {
                sb[j] = 'S'; // Append 'S' to the current row
            }
        }
        
        // Print the constructed row of the island
        printf("%s\n", sb);
    }
}

