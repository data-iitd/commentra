#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    print(x, n);
    return 0;
}

// Method to print based on the value of x and n
void print(int x, int n) {
    int max = n * 2 - 1; // Calculate the maximum value based on n
    if (x == 1 || x == max) { // Check if x is at the edges
        printf("No\n"); // Print "No" if x is 1 or max
        return; // Exit the method
    }
    printf("Yes\n"); // Print "Yes" if x is within the valid range
    char sep = '\n'; // Get the system's line separator
    char *ans = malloc(sizeof(char) * (max + 1)); // Allocate memory for the string
    for (int i = x + n - 1; i < x + n + max - 1; i++) { // Generate a stream of numbers
        ans[i - x - n + 1] = (i % max + 1) + sep; // Map each number to the required format
    }
    ans[max] = '\0'; // Terminate the string
    printf("%s", ans); // Print the constructed string
    free(ans); // Free the allocated memory
}

