
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[100001], t[100001];
    scanf("%s", s);
    scanf("%s", t);

    int ls = strlen(s);
    int lt = strlen(t);

    char ans[100001];
    int count = 0;

    for (int i = 0; i <= ls - lt; i++) {
        int flag = 1;
        for (int j = 0; j < lt; j++) {
            if (s[i + j]!= t[j] && s[i + j]!= '?') {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (int j = 0; j < ls; j++) {
                if (j >= i && j < i + lt) {
                    ans[j] = t[j - i];
                } else if (s[j] == '?') {
                    ans[j] = 'a';
                } else {
                    ans[j] = s[j];
                }
            }
            ans[ls] = '\0';
            printf("%s\n", ans);
            count++;
        }
    }
    if (count == 0) {
        printf("UNRESTORABLE\n");
    }

    return 0;
}
