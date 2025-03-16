#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char s[n + 1];
    char t[n + 1];
    
    scanf("%s", s);
    scanf("%s", t);
    
    if (strcmp(s, t) == 0) {
        printf("%d\n", n);
    } else {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i; j++) {
                if (s[i + j] != t[j]) {
                    break;
                }
                if (j == n - i - 1) {
                    cnt = n - i;
                }
            }
        }
        printf("%d\n", 2 * n - cnt);
    }
    
    return 0;
}

// <END-OF-CODE>
