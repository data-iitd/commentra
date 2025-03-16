#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 0x7FFFFFFF
#define MOD 1000000007

int main() {
    char s[100001];
    scanf("%s", s);

    int len = strlen(s);
    if (len == 1) {
        printf("0\n");
        return 0;
    }

    int count[26] = {0};
    for (int i = 0; i < len; i++) {
        count[s[i] - 'a']++;
    }

    int min_count = INF;
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0 && count[i] < min_count) {
            min_count = count[i];
        }
    }

    int ans = min_count * 2;
    printf("%d\n", ans);

    return 0;
}
