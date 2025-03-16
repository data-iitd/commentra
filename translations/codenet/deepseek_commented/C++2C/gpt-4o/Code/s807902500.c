#include <stdio.h>
#include <string.h>

int main() {
    char s[100], t[100]; // Assuming maximum length of strings is 99 characters
    scanf("%s %s", s, t); // Read two strings from standard input

    // Concatenate s with itself to double its length
    strcat(s, s);

    // Check if t is a substring of the doubled s
    // Use strstr to find the substring
    // If found, strstr returns a pointer; otherwise, it returns NULL
    puts(strstr(s, t) != NULL ? "Yes" : "No");

    return 0;
}

// <END-OF-CODE>
