_
#include <stdio.h>
#include <stdlib.h>

int main() {
    char S[1000000], T[100000];
    scanf("%s", S);
    scanf("%s", T);

    char A[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r','s', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int res = 1;

    for (int i = 0; i < 26; i++) {
        int sIdx = -1;
        for (int j = 0; j < strlen(S); j++) {
            if (S[j] == A[i]) {
                sIdx = j;
                break;
            }
        }
        if (sIdx == -1) continue;

        char t = T[sIdx];

        int idx = 0;
        while (idx < strlen(S)) {
            if (S[idx] == A[i]) {
                if (S[idx]!= T[idx]) {
                    res = 0;
                    break;
                } else {
                    idx++;
                }
            } else if (T[idx] == A[i]) {
                res = 0;
                break;
            } else {
                break;
            }
        }
        if (!res) break;
    }

    if (res) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
