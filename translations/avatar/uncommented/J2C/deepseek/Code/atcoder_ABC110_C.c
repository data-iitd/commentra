#include <stdio.h>
#include <string.h>

int main() {
    char S[100], T[100];
    char A[] = "abcdefghijklmnopqrstuvwxyz";
    int sIdx, idx;
    char t;
    int res = 1;

    scanf("%s", S);
    scanf("%s", T);

    for (int i = 0; i < strlen(A); i++) {
        char s = A[i];
        sIdx = strchr(S, s) - S;
        if (sIdx < 0) continue;
        t = T[sIdx];
        idx = 0;
        while (idx < strlen(S)) {
            if (strchr(S + idx, s) != NULL) {
                if (strchr(S + idx, s) - S != strchr(T + idx, t) - T) {
                    res = 0;
                    break;
                } else {
                    idx = (strchr(S + idx, s) - S) + 1;
                }
            } else if (strchr(T + idx, t) != NULL) {
                res = 0;
                break;
            } else {
                break;
            }
        }
        if (!res) break;
    }

    if (res) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
