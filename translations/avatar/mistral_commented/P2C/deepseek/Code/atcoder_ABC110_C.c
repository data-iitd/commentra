#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a function named 'run' that takes two arguments 's' and 't'
char* run(char* s, char* t) {
    // Calculate the length of the strings
    int len_s = strlen(s);
    int len_t = strlen(t);

    // If the lengths of the strings are not equal, they cannot have the same frequency distribution
    if (len_s != len_t) {
        return "No";
    }

    // Create arrays to count the occurrences of each character in strings 's' and 't'
    int count_s[256] = {0};
    int count_t[256] = {0};

    // Count the occurrences of each character in string 's'
    for (int i = 0; i < len_s; i++) {
        count_s[(unsigned char)s[i]]++;
    }

    // Count the occurrences of each character in string 't'
    for (int i = 0; i < len_t; i++) {
        count_t[(unsigned char)t[i]]++;
    }

    // Compare the arrays of counts for equality
    for (int i = 0; i < 256; i++) {
        if (count_s[i] != count_t[i]) {
            return "No";
        }
    }

    // If the arrays are equal, then the strings have the same frequency distribution of characters
    // and thus are identical, so return "Yes"
    return "Yes";
}

// Define a function named 'main' that takes no arguments
void main() {
    // Buffer to read input strings
    char s[1000], t[1000];

    // Taking input strings 's' and 't' from the user
    scanf("%s", s);
    scanf("%s", t);

    // Calling the 'run' function with strings 's' and 't' as arguments and printing the result
    printf("%s\n", run(s, t));
}
