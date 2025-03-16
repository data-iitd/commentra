
#include <stdio.h>
#include <string.h>

int main() {
    char s[100001];
    fgets(s, 100001, stdin);
    s[strlen(s) - 1] = '\0';
    char *p = s;
    long long cnt = 0, tmp = 0;
    while (*p!= '\0') {
        if (*p == 'A') {
            tmp++;
        } else if (*p == 'D') {
            cnt += tmp;
        } else {
            tmp = 0;
        }
        p++;
    }
    printf("%lld\n", cnt);
    return 0;
}
//END-OF-CODE