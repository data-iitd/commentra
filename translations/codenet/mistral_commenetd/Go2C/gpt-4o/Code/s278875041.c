// Importing required libraries
#include <stdio.h>
#include <string.h>

int main() {
    // Declaring a variable 'a' of type string
    char a[100]; // Assuming a maximum length of 99 characters + 1 for null terminator

    // Reading a string input from the user using scanf
    scanf("%s", a);

    // Declaring a temporary variable 'tmp' of type string
    char tmp[100];
    strcpy(tmp, a);

    // Replacing all occurrences of '1' with '0' in the string 'tmp'
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] == '1') {
            tmp[i] = '0';
        }
    }

    // Declaring another variable 'b' to store the result
    char b[100];
    strcpy(b, tmp);

    // Replacing all occurrences of '9' with '1' in the string 'b'
    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] == '9') {
            b[i] = '1';
        }
    }

    // Declaring another variable 'ans' to store the final result
    char ans[100];
    strcpy(ans, b);

    // Replacing all occurrences of '0' with '9' in the string 'ans'
    for (int i = 0; ans[i] != '\0'; i++) {
        if (ans[i] == '0') {
            ans[i] = '9';
        }
    }

    // Printing the final answer using printf
    printf("%s\n", ans);

    return 0;
}

// <END-OF-CODE>
