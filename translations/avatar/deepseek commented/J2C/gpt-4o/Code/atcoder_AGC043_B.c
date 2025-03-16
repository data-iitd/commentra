#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

// This function calculates a result based on a given string and character.
int cal(const char *s, char c) {
    int n = strlen(s);
    int m = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == c && (m & i) == i) {
            ans ^= 1;
        }
    }
    return ans;
}

// This function is responsible for solving the problem by processing the input and outputting the result.
void solve() {
    int n;
    scanf("%d", &n);
    char s[MAX_LENGTH];
    scanf("%s", s);
    
    char sb[MAX_LENGTH];
    int sb_index = 0;

    for (int i = 1; i < n; i++) {
        sb[sb_index++] = abs(s[i] - s[i - 1]) + '0'; // Convert to character
    }
    sb[sb_index] = '\0'; // Null-terminate the string

    if (n == 2) {
        printf("%c\n", sb[0]);
        return;
    }

    if (strchr(sb, '1')) {
        printf("%d\n", cal(sb, '1'));
    } else {
        printf("%d\n", cal(sb, '2') * 2);
    }
}

// The entry point of the program where the solve function is called.
int main() {
    solve();
    return 0;
}
