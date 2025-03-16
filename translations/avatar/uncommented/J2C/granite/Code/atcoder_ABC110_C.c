
#include <stdio.h>
#include <string.h>

int main() {
    char S[101], T[101];
    scanf("%s", S);
    scanf("%s", T);
    char A[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int res = 1;
    for (int i = 0; i < 26; i++) {
        char *s = strchr(S, A[i]);
        if (s == NULL) continue;
        char t = T[s - S];
        int idx = 0;
        while (1) {
            char *s2 = strchr(S + idx, A[i]);
            if (s2 == NULL) {
                char *t2 = strchr(T + idx, t);
                if (t2 == NULL) break;
                else {
                    res = 0;
                    break;
                }
            } else {
                if (s2 - S!= T[s2 - S] - t) {
                    res = 0;
                    break;
                } else {
                    idx = s2 - S + 1;
                }
            }
        }
        if (res == 0) break;
    }
    if (res == 1) printf("Yes\n");
    else printf("No\n");
    return 0;
}
//END-OF-CODE