#include <stdio.h>
#include <string.h>

int main() {
    char S[1001], T[1001];
    scanf("%s", S);
    scanf("%s", T);

    char A[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int res = 1;

    for (int i = 0; i < 26; i++) {
        int sIdx = -1;
        while ((sIdx = strchr(S, A[i]) - S) != -1) {
            char t = T[sIdx];
            int idx = 0;
            while (idx < strlen(S)) {
                if ((strchr(S, A[i] + idx) != NULL) && (strchr(S, A[i] + idx) - S != sIdx)) {
                    res = 0;
                    break;
                } else if ((strchr(T, t + idx) != NULL) && (strchr(T, t + idx) - T != sIdx)) {
                    res = 0;
                    break;
                }
                idx++;
            }
            if (res == 0) break;
        }
        if (res == 0) break;
    }

    if (res) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
