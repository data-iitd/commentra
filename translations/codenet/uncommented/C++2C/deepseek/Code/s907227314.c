#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    scanf("%s", s);
    int a, z;
    for(int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            a = i;
            break;
        }
    }
    for(int i = strlen(s) - 1; i >= 0; i--) {
        if (s[i] == 'Z') {
            z = i;
            break;
        }
    }
    printf("%d\n", z - a + 1);
    return 0;
}

