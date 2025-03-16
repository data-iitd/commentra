#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    long long cnt = 0, tmp = 0;

    // Read input string
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

    // Print the result
    printf("%lld\n", cnt);

    return 0;
}

