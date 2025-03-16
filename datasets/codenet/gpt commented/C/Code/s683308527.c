#include<stdio.h>
#include<string.h>

int main() {
    int n; // Variable to store the number of lines to read
    char s[10010]; // Array to store each line of input
    char *c; // Pointer to search for the substring "Hoshino"

    // Read the number of lines to process, ignoring the newline character
    scanf("%d%*c", &n);

    // Loop to process each line of input
    while(n--) {
        // Read a line of input from stdin
        fgets(s, 1010, stdin);

        // Search for the substring "Hoshino" in the input line
        // Replace the character following "Hoshino" with 'a'
        while(c = strstr(s, "Hoshino")) {
            *(c + 6) = 'a'; // Replace the character after "Hoshino" with 'a'
        }

        // Print the modified line
        printf("%s", s);
    }

    return 0; // Return 0 to indicate successful completion
}
