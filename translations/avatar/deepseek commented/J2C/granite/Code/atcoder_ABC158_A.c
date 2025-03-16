

#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Declare a character array to store the input string.
    scanf("%s", s); // Read the input string from the console and store it in the character array.
    if (strstr(s, "A") && strstr(s, "B")) { // Check if the string contains both 'A' and 'B' using the strstr function.
        printf("Yes\n"); // Print "Yes" if the condition is true.
    } else {
        printf("No\n"); // Print "No" if the condition is false.
    }
    return 0;
}

// C code: This is the translated C code from the given Java code.
// 