
#include <stdio.h>
#include <string.h>

int main() {
    int n, k;
    char s[100001];
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    int count[26] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (count[i] >= k) {
            res += k * k;
            printf("%d\n", res);
            return 0;
        }
        k -= count[i];
        res += count[i] * count[i];
    }
    printf("%d\n", res);
    return 0;
}

