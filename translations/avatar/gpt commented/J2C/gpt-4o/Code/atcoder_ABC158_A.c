#include <stdio.h>
#include <string.h>

void solve(int testNumber, char *s) {
    // Check if the string contains both 'A' and 'B'
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) {
        // If both characters are present, print "Yes"
        printf("Yes\n");
    } else {
        // If either character is missing, print "No"
        printf("No\n");
    }
}

int main() {
    // Initialize input string
    char s[100]; // Assuming the input string will not exceed 99 characters

    // Read the input string
    scanf("%s", s);

    // Call the solve function with test number 1
    solve(1, s);

    return 0;
}

// <END-OF-CODE>
