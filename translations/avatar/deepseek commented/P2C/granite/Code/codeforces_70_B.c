

#include <stdio.h>
#include <regex.h>

int main() {
    int n;
    scanf("%d", &n);
    regex_t regex;
    regmatch_t match[1];
    char input[1000];
    int ans = 1, sumL = 0;
    while (fgets(input, 1000, stdin)) {
        regcomp(&regex, "[.?!]", 0);
        if (regexec(&regex, input, 1, match, 0) == 0) {
            char *s = input + match[0].rm_so;
            s[match[0].rm_eo - match[0].rm_so - 1] = '.';
            int L = strlen(s);
            if (L > 1) {
                if (L > n) {
                    printf("Impossible\n");
                    return 0;
                }
                if (sumL + L + (sumL > 0) > n) {
                    ans++;
                    sumL = L;
                } else {
                    sumL = sumL + L + (sumL > 0);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
