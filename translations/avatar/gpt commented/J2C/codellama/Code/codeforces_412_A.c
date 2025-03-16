#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    char a[100];
    
    // Reading two integers n and k from user input
    scanf("%d %d", &n, &k);
    
    // Reading a string a from user input
    scanf("%s", a);
    
    // Check if k is greater than half of n
    if (k > n / 2) {
        // If true, move to the right until k equals n
        while (k < n) {
            printf("RIGHT\n"); // Output "RIGHT" for each step to the right
            k++; // Increment k
        }
    } else {
        // If false, move to the left until k equals 1
        while (k > 1) {
            printf("LEFT\n"); // Output "LEFT" for each step to the left
            k--; // Decrement k
        }
    }
    
    // If k equals 1, print the characters of the string from left to right
    if (k == 1) {
        for (int i = 0; i < strlen(a); i++) {
            printf("PRINT %c\n", a[i]); // Print the current character
            // If not at the last character, output "RIGHT"
            if ((i + 1) < strlen(a)) {
                printf("RIGHT\n");
            }
        }
    } else {
        // If k is not 1, print the characters of the string from right to left
        for (int i = strlen(a) - 1; i >= 0; i--) {
            printf("PRINT %c\n", a[i]); // Print the current character
            // If not at the first character, output "LEFT"
            if ((i - 1) >= 0) {
                printf("LEFT\n");
            }
        }
    }
    
    printf("