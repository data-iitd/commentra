#include <stdio.h>
#include <string.h>

int main() {
    // Declare two character arrays to store user input.
    char s[100], t[100];

    // Read user input and store it in arrays s and t respectively.
    scanf("%s %s", s, t);

    // Concatenate the string s with itself.
    strcat(s, s);

    // Check if the substring t is present in the string s. If it is, print "Yes". Otherwise, print "No".
    if (strstr(s, t) != NULL) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}

// <END-OF-CODE>
