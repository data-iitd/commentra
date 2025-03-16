#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    char S[N + 1];
    scanf("%s", S);
    int step = 1;
    while (K > 0) {
        char T[N + 1];
        strcpy(T, S);
        int i;
        for (i = 0; i < N; i++) {
            T[i] = S[N - i - 1];
        }
        char revU[2 * N + 1];
        strcpy(revU, S);
        strcat(revU, T);
        int j;
        for (j = 0; j < 2 * N; j++) {
            revU[j] = revU[2 * N - j - 1];
        }
        char sDash[N + 1];
        strcpy(sDash, S);
        int k;
        for (k = 0; k < N; k += step) {
            char tmp[N + 1];
            strcpy(tmp, revU + k);
            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                if (step == 1) {
                    break;
                }
            }
        }
        if (step == 1) {
            if (pow(2, K) > N) {
                char c = sDash[0];
                int i;
                for (i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                exit(0);
            }
        }
        step += step;
        K--;
        strcpy(S, sDash);
    }
    int i;
    for (i = 0; i < N; i++) {
        printf("%c", S[N - i - 1]);
    }
    printf("\n");
    return 0;
}

