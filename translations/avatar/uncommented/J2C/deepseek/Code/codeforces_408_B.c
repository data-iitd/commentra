#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isValid(char* s1, char* s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    bool map[256] = { false };
    for (int i = 0; i < n1; i++) {
        map[(unsigned char)s1[i]] = true;
    }
    for (int i = 0; i < n2; i++) {
        if (!map[(unsigned char)s2[i]]) return false;
    }
    return true;
}

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    if (!isValid(s1, s2)) {
        printf("-1\n");
    } else {
        int m1[256] = { 0 }, m2[256] = { 0 };
        for (int i = 0; s1[i] != '\0'; i++) {
            m1[(unsigned char)s1[i]]++;
        }
        for (int i = 0; s2[i] != '\0'; i++) {
            m2[(unsigned char)s2[i]]++;
        }
        int ans = 0;
        bool hs[256] = { false };
        for (int i = 0; s2[i] != '\0'; i++) {
            if (!hs[(unsigned char)s2[i]]) {
                hs[(unsigned char)s2[i]] = true;
                int x1 = m1[(unsigned char)s2[i]];
                int x2 = m2[(unsigned char)s2[i]];
                x1 = x1 < x2 ? x1 : x2;
                ans += x1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
