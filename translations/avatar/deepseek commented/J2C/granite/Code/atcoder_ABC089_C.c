

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[100005][5];
    int m = 0, a = 0, r = 0, c = 0, h = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
        if (strcmp(s[i], "M") == 0) {
            m++;
        } else if (strcmp(s[i], "A") == 0) {
            a++;
        } else if (strcmp(s[i], "R") == 0) {
            r++;
        } else if (strcmp(s[i], "C") == 0) {
            c++;
        } else if (strcmp(s[i], "H") == 0) {
            h++;
        }
    }
    long long ans = 0;
    ans += (long long)m * a * r;
    ans += (long long)m * a * c;
    ans += (long long)m * a * h;
    ans += (long long)m * r * c;
    ans += (long long)m * r * h;
    ans += (long long)m * c * h;
    ans += (long long)a * r * c;
    ans += (long long)a * r * h;
    ans += (long long)a * c * h;
    ans += (long long)r * c * h;
    printf("%lld\n", ans);
    return 0;
}
// Translate the above C code to Python and end with comment "