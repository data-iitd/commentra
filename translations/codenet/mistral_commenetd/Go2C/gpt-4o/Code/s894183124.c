// Include standard input/output library
#include <stdio.h>
#include <string.h>

int main() {
    // Declare and initialize two variables: n of type int and s of type char array
    int n;
    char s[100]; // Assuming a maximum length for the string

    // Use scanf to read input from the standard input
    scanf("%d", &n);
    scanf("%s", s);

    // Use a variable to count occurrences of "ABC"
    int count = 0;
    char *ptr = s;

    // Loop through the string to count occurrences of "ABC"
    while ((ptr = strstr(ptr, "ABC")) != NULL) {
        count++;
        ptr++; // Move past the current occurrence
    }

    // Print the result
    printf("%d\n", count);

    return 0;
}

// <END-OF-CODE>
