#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    scanf("%s", s);
    int cnt = 0, tmp = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'A') {
            tmp++;
        } else if (s[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

