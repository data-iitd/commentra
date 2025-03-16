#include <stdio.h>
#include <string.h>

void solve(int testNumber, char *s) {
    if (strchr(s, 'A') != NULL && strchr(s, 'B') != NULL) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    solve(1, s);
    return 0;
}

// <END-OF-CODE>
