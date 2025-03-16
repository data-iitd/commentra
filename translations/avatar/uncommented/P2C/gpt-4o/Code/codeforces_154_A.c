#include <stdio.h>
#include <string.h>

int main() {
    char s[100]; // Assuming the input string will not exceed 99 characters
    int n;
    scanf("%s", s);
    scanf("%d", &n);
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        char x[3]; // To hold the two characters and the null terminator
        scanf("%s", x);
        
        int a = 0, b = 0;
        for (int j = 0; j < strlen(s); j++) {
            if (s[j] == x[0]) {
                a++;
            } else if (s[j] == x[1]) {
                b++;
            } else {
                ans += (a < b) ? a : b; // Add the minimum of a and b to ans
                a = 0; // Reset a and b
                b = 0;
            }
        }
        ans += (a < b) ? a : b; // Add the minimum of a and b to ans for the last segment
    }
    
    printf("%d\n", ans);
    return 0;
}

// <END-OF-CODE>
