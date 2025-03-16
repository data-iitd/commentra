#include <stdio.h>
#include <string.h>

int main() {
    char s[101]; // Declaring a character array to store the input string.
    scanf("%s", s); // Reading the input string from the console.
    if (strstr(s, "A") != NULL && strstr(s, "B") != NULL) { // Checking if the string contains both 'A' and 'B'.
        printf("Yes\n"); // Printing "Yes" if the condition is true.
    } else {
        printf("No\n"); // Printing "No" if the condition is false.
    }
    return 0; // Returning 0 to indicate successful execution.
}

