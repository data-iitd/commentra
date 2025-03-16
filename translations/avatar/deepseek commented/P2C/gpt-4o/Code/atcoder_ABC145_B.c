#include <stdio.h>
#include <string.h>

int main() {
    int n;
    // Take an integer input from the user
    scanf("%d", &n);
    
    // Clear the input buffer
    getchar();
    
    char s[100]; // Assuming the maximum length of the string is 100
    // Take a string input from the user
    fgets(s, sizeof(s), stdin);
    
    // Remove the newline character from the string if present
    s[strcspn(s, "\n")] = 0;

    // Check if n is odd
    if (n % 2 != 0) {
        // Print 'No' if n is odd
        printf("No\n");
    } 
    // If n is even, compare the first half of the string with the second half
    else {
        int half = n / 2;
        if (strncmp(s, s + half, half) == 0) {
            // Print 'Yes' if the first half is equal to the second half
            printf("Yes\n");
        } else {
            // Print 'No' if the first half is not equal to the second half
            printf("No\n");
        }
    }

    return 0;
}
// <END-OF-CODE>
