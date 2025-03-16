

#include <stdio.h>
#include <string.h>

int main() {
    char stdin[100];  // Declare a character array to store the input
    char s[100];  // Declare a character array to store the input
    char result[10];  // Declare a character array to store the result

    fgets(stdin, 100, stdin);  // Read input from the user and store it in the variable stdin
    strcpy(s, stdin);  // Copy the input to the variable s

    // Check if the string s contains both "A" and "B"
    if (strstr(s, "A")!= NULL && strstr(s, "B")!= NULL) {
        strcpy(result, "Yes");  // If both "A" and "B" are in the string, copy "Yes" to the variable result
    } else {
        strcpy(result, "No");  // Otherwise, copy "No" to the variable result
    }

    printf("%s\n", result);  // Print the result

    return 0;
}

Translate the above C code to Java and end with comment "