#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[1000];
    scanf("%d %s", &n, s);
    int count = 0;
    for (int i = 0; i <= strlen(s) - 3; i++) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
