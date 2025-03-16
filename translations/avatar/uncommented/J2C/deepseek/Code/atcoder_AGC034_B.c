#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100005];
    long cnt = 0;
    long tmp = 0;
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            tmp++;
        } else if (s[i] == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
    }
    printf("%ld\n", cnt);
    return 0;
}
