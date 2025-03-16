#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#include <assert.h>

int main() {
    char s[100000];
    scanf("%s", s);
    int a[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        a[s[i] - 'a']++;
    }
    int ans = INT_MAX;
    for (int i = 0; i < 26; i++) {
        if (a[i] > 0) {
            ans = min(ans, a[i] * 2);
        }
    }
    printf("%d\n", ans);
    return 0;
}

