
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    scanf("%s", s);
    int n = 0;
    for (int i = 0; s[i]!= '\0'; i++) {
        if (s[i] == 'o') {
            n++;
        }
    }
    int result = 700 + n * 100;
    printf("%d\n", result);
    return 0;
}

// The code ends here