#include <stdio.h>
#include <string.h>

int main() {
    // Declare a character array to hold user input
    char a[100];
    
    // Read input from the user and store it in `a`
    fgets(a, sizeof(a), stdin);
    
    // Remove the newline character if present
    a[strcspn(a, "\n")] = '\0';
    
    // Replace all occurrences of "1" with "0" in the string `a`
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '1') {
            a[i] = '0';
        }
    }
    
    // Replace all occurrences of "9" with "1" in the string `a`
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '9') {
            a[i] = '1';
        }
    }
    
    // Replace all occurrences of "0" with "9" in the string `a`
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == '0') {
            a[i] = '9';
        }
    }
    
    // Print the final result to the console
    printf("%s\n", a);
    
    return 0;
}
