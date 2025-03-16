#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char s[100], t[100];
    int h1, m1, h2, m2;
    scanf("%s", s);
    scanf("%s", t);
    sscanf(s, "%d:%d", &h1, &m1);
    sscanf(t, "%d:%d", &h2, &m2);
    printf("%02d:%02d", h1 - h2, m1 - m2);
    return 0;
}
