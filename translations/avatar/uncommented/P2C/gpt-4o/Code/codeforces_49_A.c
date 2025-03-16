#include <stdio.h>
#include <string.h>

int main() {
    char a[100]; // Assuming the input will not exceed 99 characters
    fgets(a, sizeof(a), stdin); // Read input

    char vo[] = "aeiouyAEIOUY"; // Vowels including 'y' and 'Y'
    int length = strlen(a);

    for (int i = length - 1; i >= 0; i--) {
        if (a[i] == ' ' || a[i] == '?') {
            continue;
        } else {
            if (strchr(vo, a[i]) != NULL) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
            break;
        }
    }

    return 0;
}

// <END-OF-CODE>
