#include <stdio.h>
#include <string.h>

int main() {
    char s[101]; // Assuming the input string length is at most 100

    // Read the input string
    scanf("%s", s);

    // Check if the string contains both 'A' and 'B'
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) {
        // If both characters are present, print "Yes"
        printf("Yes\n");
    } else {
        // If either character is missing, print "No"
        printf("No\n");
    }

    return 0;
}
