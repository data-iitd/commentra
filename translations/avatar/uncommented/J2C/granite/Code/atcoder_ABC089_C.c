
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[10];
    long long cnt[5] = {0};
    for (int i = 0; i < n; i++) {
        scanf("%s", s);
        if (strcmp(s, "M") == 0) {
            cnt[0]++;
        } else if (strcmp(s, "A") == 0) {
            cnt[1]++;
        } else if (strcmp(s, "R") == 0) {
            cnt[2]++;
        } else if (strcmp(s, "C") == 0) {
            cnt[3]++;
        } else if (strcmp(s, "H") == 0) {
            cnt[4]++;
        }
    }
    long long res = cnt[0] * cnt[1] * cnt[2] + cnt[0] * cnt[1] * cnt[3] + cnt[0] * cnt[1] * cnt[4] + cnt[0] * cnt[2] * cnt[3] + cnt[0] * cnt[2] * cnt[4] + cnt[0] * cnt[3] * cnt[4] + cnt[1] * cnt[2] * cnt[3] + cnt[1] * cnt[2] * cnt[4] + cnt[1] * cnt[3] * cnt[4] + cnt[2] * cnt[3] * cnt[4];
    printf("%lld\n", res);
    return 0;
}
//END-OF-CODE