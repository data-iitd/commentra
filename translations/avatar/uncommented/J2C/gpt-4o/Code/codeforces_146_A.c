#include <stdio.h>
#include <string.h>

int main() {
    int x = 0, y = 0;
    int t = 0;
    int n;
    scanf("%d", &n);
    
    char str[n + 1]; // +1 for null terminator
    scanf("%s", str);
    
    for (int i = 0; i < n; i++) {
        if (str[i] != '4' && str[i] != '7') {
            t = 1;
            break; // Exit the loop early if a non-4/7 character is found
        }
    }
    
    if (t == 1) {
        printf("NO\n");
    } else {
        for (int i = 0; i < n / 2; i++) {
            x += str[i] - '0'; // Convert char to int
        }
        for (int i = n - 1; i >= (n / 2); i--) {
            y += str[i] - '0'; // Convert char to int
        }
        if (x == y) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    
    return 0;
}

// <END-OF-CODE>
