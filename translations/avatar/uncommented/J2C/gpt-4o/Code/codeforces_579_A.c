#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[32]; // Assuming 32 bits for the binary representation
    int index = 0;

    while (n > 0) {
        int x = n % 2;
        n /= 2;
        s[index++] = x + '0'; // Convert int to char
    }
    s[index] = '\0'; // Null-terminate the string

    int ans = 0;
    for (int i = 0; i < index; i++) {
        if (s[i] == '1') {
            ans++;
        }
    }
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
