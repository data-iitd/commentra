

#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Input string
    scanf("%s", s); // Read the input string

    // Check if the string contains both 'A' and 'B'
    if (strstr(s, "A") && strstr(s, "B")) {
        printf("Yes\n"); // Print "Yes" if both characters are present
    } else {
        printf("No\n"); // Print "No" if either character is missing
    }

    return 0;
}
