#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

#define MAX_CHARS 26

int main(int argc, char *argv[]) {
    char s[MAX_CHARS];
    scanf("%s", s);

    int ans = 0;
    int count[MAX_CHARS];
    for (int i = 0; i < MAX_CHARS; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < MAX_CHARS; i++) {
        ans += count[i] * 2;
    }
    printf("%d\n", ans);
    return 0;
}

