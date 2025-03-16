#include <stdio.h>

int main() {
    char n[4]; // Array to hold the input string (3 digits + null terminator)
    scanf("%3s", n); // Read up to 3 characters

    for (int i = 0; i < 3; i++) {
        if (n[i] == '7') {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}

// <END-OF-CODE>
