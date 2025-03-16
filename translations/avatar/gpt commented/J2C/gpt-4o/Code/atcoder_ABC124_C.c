#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100000

void solve(const char *x) {
    int a1 = 0, a2 = 0;
    int length = strlen(x);
    char a[MAX_LENGTH], b[MAX_LENGTH];

    // Copy the input string to a and b
    strcpy(a, x);
    strcpy(b, x);

    // First pass: modify 'a' from left to right
    for (int i = 1; i < length; i++) {
        if (a[i] == a[i - 1]) {
            a[i] = (a[i] == '1') ? '0' : '1';
            a1++;
        }
    }

    // Second pass: modify 'b' from right to left
    for (int i = length - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            b[i - 1] = (b[i - 1] == '1') ? '0' : '1';
            a2++;
        }
    }

    // Output the minimum number of changes made in either pass
    printf("%d\n", (a1 < a2) ? a1 : a2);
}

int main() {
    char x[MAX_LENGTH];

    // Read the input string
    scanf("%s", x);

    // Solve the problem
    solve(x);

    return 0;
}

// <END-OF-CODE>
