#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[100]; // Assuming the maximum length of the string is 100
    scanf("%d %s", &n, s);
    
    int count = 0;
    for (int i = 0; i <= n - 3; i++) {
        if (strncmp(&s[i], "ABC", 3) == 0) {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
// <END-OF-CODE>
