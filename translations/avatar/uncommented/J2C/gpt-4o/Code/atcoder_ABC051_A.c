#include <stdio.h>
#include <string.h>

int main() {
    char a[1000]; // Assuming the input will not exceed 999 characters
    fgets(a, sizeof(a), stdin); // Read a line of input

    // Replace commas with spaces
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == ',') {
            a[i] = ' ';
        }
    }

    printf("%s", a); // Print the modified string
    return 0;
}

// <END-OF-CODE>
