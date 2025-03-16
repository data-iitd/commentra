

#include <stdio.h>
#include <ctype.h>

int main() {
    char s[100];
    scanf("%s", s);
    int l = strlen(s);
    char ans[3] = "AC";
    if (s[0]!= 'A') {
        ans[0] = 'W';
        ans[1] = 'A';
    }
    int cnt = 0;
    for (int i = 1; i < l; i++) {
        if (isupper(s[i])) {
            if (i == 1 || i == l - 1 || s[i]!= 'C') {
                ans[0] = 'W';
                ans[1] = 'A';
            }
            cnt++;
        }
    }
    if (cnt!= 1) {
        ans[0] = 'W';
        ans[1] = 'A';
    }
    printf("%s\n", ans);
    return 0;
}
// END-OF-CODE