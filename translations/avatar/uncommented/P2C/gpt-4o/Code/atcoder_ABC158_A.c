#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    fgets(s, sizeof(s), stdin); // Read input from stdin

    // Remove newline character if present
    s[strcspn(s, "\n")] = 0;

    // Check for presence of 'A' and 'B'
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
