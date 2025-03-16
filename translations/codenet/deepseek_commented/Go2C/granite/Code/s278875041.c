
#include <stdio.h>
#include <string.h>

int main() {
    // Declare a string variable to hold user input
    char a[100];
    
    // Read input from the user and store it in `a`
    scanf("%s", a);
    
    // Replace all occurrences of "1" with "0" in the string `a`
    char tmp[100];
    strcpy(tmp, a);
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '1') {
            tmp[i] = '0';
        }
    }
    
    // Store the result of the first replacement in a temporary variable `tmp`
    // Replace all occurrences of "9" with "1" in the string `tmp`
    for (int i = 0; i < strlen(tmp); i++) {
        if (tmp[i] == '9') {
            tmp[i] = '1';
        }
    }
    
    // Store the result of the second replacement in the variable `b`
    // Replace all occurrences of "0" with "9" in the string `b`
    char b[100];
    strcpy(b, tmp);
    for (int i = 0; i < strlen(b); i++) {
        if (b[i] == '0') {
            b[i] = '9';
        }
    }
    
    // Print the final result to the console
    printf("%s\n", b);
    
    return 0;
}
