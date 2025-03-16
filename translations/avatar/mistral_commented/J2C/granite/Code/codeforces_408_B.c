

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char *s1, char *s2) {
    int n1 = strlen(s1);
    int n2 = strlen(s2);

    bool map[256] = {false};

    for (int i = 0; i < n1; i++) {
        map[s1[i]] = true;
    }

    for (int i = 0; i < n2; i++) {
        if (!map[s2[i]]) {
            return false;
        }
    }

    return true;
}

int main() {
    char s1[1000], s2[1000];
    scanf("%s %s", s1, s2);

    if (isValid(s1, s2) == false) {
        printf("-1\n");
        return 0;
    }

    int ans = 0;
    int count[256] = {0};

    for (int i = 0; i < strlen(s1); i++) {
        count[s1[i]]++;
    }

    for (int i = 0; i < strlen(s2); i++) {
        ans += count[s2[i]];
        count[s2[i]] = 0;
    }

    printf("%d\n", ans);

    return 0;
}

Translate the above C code to Python and end with comment "