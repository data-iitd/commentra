#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MOD 1000000007

// Function to read input as a string
char* read_input() {
    char *buffer = malloc(1000);
    fgets(buffer, 1000, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove newline character
    return buffer;
}

// Main function 'main_b'
void main_b() {
    char *s = read_input();
    int pp = 0;
    int na = 0;
    int len = strlen(s);

    for (int i = len - 1; i >= 0; i--) {
        int c = s[i] - '0'; // Convert char to int
        int cc = na + c;
        na = 0;

        if (cc <= 4) {
            pp += cc;
        } else {
            if (i == len - 1) {
                pp += 1;
            }
            pp += 10 - cc;
        }
    }

    printf("%d\n", pp);
    free(s);
}

// Main function 'main'
int main() {
    char *s = read_input();
    int pmin = 1000;
    int mmin = 0;

    // Add a leading zero to the input string
    char *new_s = malloc(strlen(s) + 2);
    new_s[0] = '0';
    strcpy(new_s + 1, s);

    int len = strlen(new_s);
    for (int i = len - 1; i >= 0; i--) {
        int c = new_s[i] - '0'; // Convert char to int
        int npmin = (pmin + 10 - (c + 1) < mmin + 10 - c) ? (pmin + 10 - (c + 1)) : (mmin + 10 - c);
        int nmmin = (pmin + c + 1 < mmin + c) ? (pmin + c + 1) : (mmin + c);

        pmin = npmin;
        mmin = nmmin;
    }

    printf("%d\n", (pmin < mmin) ? pmin : mmin);
    free(s);
    free(new_s);
    return 0;
}

// <END-OF-CODE>
