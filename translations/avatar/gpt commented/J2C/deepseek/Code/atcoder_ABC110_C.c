#include <stdio.h>
#include <string.h>

int main() {
    char S[100], T[100];
    scanf("%s", S);
    scanf("%s", T);

    char A[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int res = 1;

    for (int i = 0; i < 26; i++) {
        char s = A[i];
        int sIdx = strchr(S, s) ? strchr(S, s) - S : -1;

        if (sIdx < 0) continue;

        char t = T[sIdx];
        int idx = 0;

        while (idx < strlen(S)) {
            if (strchr(S + idx, s)) {
                if (strchr(S + idx, s) - S != strchr(T + idx, t) - T) {
                    res = 0;
                    break;
                } else {
                    idx = strchr(S + idx, s) - S + 1;
                }
            } else if (strchr(T + idx, t)) {
                res = 0;
                break;
            } else {
                break;
            }
        }
        if (!res) break;
    }

    if (res) 
        printf("Yes\n");
    else 
        printf("No\n");

    return 0;
}
