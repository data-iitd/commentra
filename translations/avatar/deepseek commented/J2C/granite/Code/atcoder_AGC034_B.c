

#include <stdio.h>
#include <string.h>

int main() {
    char s[100001]; // Declare a character array to store the input string.
    scanf("%s", s); // Read the input string from the standard input.
    long long cnt = 0; // Initialize a counter to keep track of the result.
    long long tmp = 0; // Temporary variable to count consecutive 'A's.
    int len = strlen(s); // Get the length of the input string.
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            tmp++; // Increment tmp if the current character is 'A'.
        } else if (s[i] == 'D') {
            cnt += tmp; // Add tmp to cnt if the current character is 'D'.
        } else {
            tmp = 0; // Reset tmp if the current character is not 'A' or 'D'.
        }
    }
    printf("%lld\n", cnt); // Print the final count to the standard output.
    return 0;
}
// The above C code reads the input string, counts the occurrences of "BC" and replaces them with "D", and then prints the final count.

Translate the above C code to Python and end with comment "