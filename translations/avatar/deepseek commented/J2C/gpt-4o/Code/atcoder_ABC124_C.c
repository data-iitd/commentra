#include <stdio.h>
#include <string.h>

void solve(const char *x) {
    int len = strlen(x);
    char a[len + 1], b[len + 1];
    strcpy(a, x);
    strcpy(b, x);
    
    int a1 = 0, a2 = 0;

    // First loop to change characters to make the string colorful
    for (int i = 1; i < len; i++) {
        if (a[i] == a[i - 1]) {
            // Change the character to the opposite
            a[i] = (a[i] == '1') ? '0' : '1';
            a1++;
        }
    }

    // Second loop to change characters to make the string colorful
    for (int i = len - 1; i > 0; i--) {
        if (b[i] == b[i - 1]) {
            // Change the character to the opposite
            b[i - 1] = (b[i - 1] == '1') ? '0' : '1';
            a2++;
        }
    }

    // Output the minimum number of changes needed
    printf("%d\n", (a1 < a2) ? a1 : a2);
}

int main() {
    char x[100001]; // Assuming the maximum length of the input string is 100000
    scanf("%s", x);
    solve(x);
    return 0;
}

// <END-OF-CODE>
