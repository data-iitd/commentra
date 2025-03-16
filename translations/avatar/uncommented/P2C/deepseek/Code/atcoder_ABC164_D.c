#include <stdio.h>
#include <string.h>

int main() {
    char s[100000];
    int l = 2019, m[2019] = {1}, a = 0, r = 0;
    scanf("%s", s);
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        a += (s[len - 1 - i] - '0') * pow(10, i);
        a %= l;
        r += m[a];
        m[a]++;
    }
    printf("%d\n", r);
    return 0;
}
