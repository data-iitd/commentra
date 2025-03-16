#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Read the input string
    char x[100000];
    scanf("%s", x);
    // Create two char arrays to manipulate the string
    char a[100000];
    char b[100000];
    // Initialize counters for the number of changes needed
    int a1 = 0;
    int a2 = 0;

    // First loop to change characters to make the string colorful
    for (int i = 1; i < strlen(x); i++) {
        if (a[i] == a[i - 1]) {
            // Change the character to the opposite
            if (a[i] == '1') {
                a[i] = '0';
            } else {
                a[i] = '1';
            }
            // Increment the counter
            a1++;
        }
    }

    // Second loop to change characters to make the string colorful
    for (int i = strlen(x) - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            // Change the character to the opposite
            if (b[i - 1] == '1') {
                b[i - 1] = '0';
            } else {
                b[i - 1] = '1';
            }
            // Increment the counter
            a2++;
        }
    }

    // Output the minimum number of changes needed
    printf("%d\n", a1 < a2 ? a1 : a2);
    return 0;
}

