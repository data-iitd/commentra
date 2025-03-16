
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char s[10], t[10];
    scanf("%s %s", s, t);
    int h1 = (s[0] - '0') * 10 + (s[1] - '0');
    int m1 = (s[3] - '0') * 10 + (s[4] - '0');
    int h2 = (t[0] - '0') * 10 + (t[1] - '0');
    int m2 = (t[3] - '0') * 10 + (t[4] - '0');
    int h = h1 - h2;
    int m = m1 - m2;
    if (m < 0) {
        m += 60;
        h--;
    }
    printf("%d:%02d\n", h, m);
    return 0;
}
// END-OF-CODE