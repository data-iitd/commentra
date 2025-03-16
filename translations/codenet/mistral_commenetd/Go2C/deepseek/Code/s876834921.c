#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[1000];
    
    // Read a string input from the user using 'scanf' function
    scanf("%s", s);

    // Replace all occurrences of the substrings "dream" and "erase" with "D" and "E" respectively using 'str_replace' function
    str_replace(s, "dream", "D");
    str_replace(s, "erase", "E");

    // Remove the substrings "Der" and "Er" from the string 's' using 'str_replace' function
    str_replace(s, "Der", "");
    str_replace(s, "Er", "");

    // Remove leading and trailing spaces from the string 's' using 'str_trim' function
    str_trim(s);

    // Check if the string 's' is empty or not
    if (strlen(s) == 0) {
        // Print "YES" if the string 's' is empty
        printf("YES\n");
    } else {
        // Print "NO" if the string 's' is not empty
        printf("NO\n");
    }

    // End of the code
    return 0;
}

