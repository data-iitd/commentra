
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

    printf("%d\n", 700 + n * 100);

    return 0;
}
