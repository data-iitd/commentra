#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, K;
    char S[100001];
    scanf("%d %d", &N, &K);
    scanf("%s", S);

    int firstTime = 1;
    int step = 1;

    while (K > 0) {
        char T[100001];
        strcpy(T, S);
        for (int i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        T[N] = '\0';

        char revU[200002];
        strcpy(revU, S);
        strcat(revU, T);
        for (int i = 0; i < 2 * N; i++) {
            revU[i] = revU[2 * N - 1 - i];
        }
        revU[2 * N] = '\0';

        char sDash[100001];
        strcpy(sDash, S);

        for (int i = N; i >= 0; i -= step) {
            char tmp[100001];
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0';

            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                if (!firstTime) {
                    break;
                }
            }
        }

        if (firstTime) {
            firstTime = 0;
            if (pow(2, K) > N) {
                for (int i = 0; i < N; i++) {
                    printf("%c", sDash[0]);
                }
                printf("\n");
                return 0;
            }
        } else {
            step += step;
        }

        K--;
        strcpy(S, sDash);
        for (int i = 0; i < N; i++) {
            S[i] = sDash[N - 1 - i];
        }
        S[N] = '\0';
    }

    for (int i = 0; i < N; i++) {
        printf("%c", S[N - 1 - i]);
    }
    printf("\n");

    return 0;
}
