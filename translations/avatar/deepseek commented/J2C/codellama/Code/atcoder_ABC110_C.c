#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char S[100], T[100];
    char A[] = "abcdefghijklmnopqrstuvwxyz";
    bool res = true;

    scanf("%s", S);
    scanf("%s", T);

    for (int i = 0; i < 26; i++) {
        int sIdx = strchr(S, A[i]) - S;
        if (sIdx < 0) continue;

        char t = T[sIdx];

        int idx = 0;
        while (idx < strlen(S)) {
            if (strchr(S, A[i]) - S >= idx) {
                if (strchr(S, A[i]) - S != strchr(T, t) - T) {
                    res = false;
                    break;
                } else {
                    idx = strchr(S, A[i]) - S + 1;
                }
            } else if (strchr(T, t) - T >= idx) {
                res = false;
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

