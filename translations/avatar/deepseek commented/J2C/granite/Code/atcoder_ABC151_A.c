

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create a BufferedReader to read input from the console
    char buffer[1024];
    fgets(buffer, 1024, stdin);

    // Read a single line of input from the user
    char *s = buffer;

    // Increment the first character of the input by 1 and print it
    printf("%c", s[0] + 1);

    return 0;
}

// END-OF-CODE