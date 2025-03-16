#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

int isValid(char *s1, char *s2) {
    int map[MAX_CHAR] = {0};
    for (int i = 0; s1[i] != '\0'; i++) {
        map[(unsigned char)s1[i]] = 1;
    }
    for (int i = 0; s2[i] != '\0'; i++) {
        if (!map[(unsigned char)s2[i]]) {
            return 0; // false
        }
    }
    return 1; // true
}

int main() {
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);

    if (!isValid(s1, s2)) {
        printf("-1\n");
    } else {
        int m1[MAX_CHAR] = {0};
        int m2[MAX_CHAR] = {0};

        for (int i = 0; s1[i] != '\0'; i++) {
            m1[(unsigned char)s1[i]]++;
        }
        for (int i = 0; s2[i] != '\0'; i++) {
            m2[(unsigned char)s2[i]]++;
        }

        int ans = 0;
        int hs[MAX_CHAR] = {0}; // HashSet equivalent

        for (int i = 0; s2[i] != '\0'; i++) {
            if (!hs[(unsigned char)s2[i]]) {
                hs[(unsigned char)s2[i]] = 1;
                int x1 = m1[(unsigned char)s2[i]];
                int x2 = m2[(unsigned char)s2[i]];
                x1 = (x1 < x2) ? x1 : x2; // Math.min equivalent
                ans += x1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

// <END-OF-CODE>
