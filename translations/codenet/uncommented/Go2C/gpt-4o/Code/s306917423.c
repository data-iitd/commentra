#include <stdio.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    scanf("%s", s);
    int ans = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            ans++;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
