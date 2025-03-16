#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, K;
    char S[100005];
    scanf("%d", &N);
    scanf("%d", &K);
    scanf("%s", S);

    int firstTime = 1;
    int step = 1;

    while (K > 0) {
        char T[100005];
        strcpy(T, S);
        for (int i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        T[N] = '\0';

        char revU[200010];
        strcpy(revU, S);
        strcat(revU, T);
        for (int i = 0; i < 2 * N; i++) {
            revU[i] = revU[2 * N - 1 - i];
        }
        revU[2 * N] = '\0';

        char sDash[100005];
        strcpy(sDash, S);
        for (int i = N - 1; i >= 0; i -= step) {
            char tmp[100005];
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
                char c = sDash[0];
                for (int i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                exit(0);
            }
        } else {
            step += step;
        }
        K--;
        strcpy(S, sDash);
    }

    for (int i = 0; i < N; i++) {
        S[i] = S[N - 1 - i];
    }
    S[N] = '\0';
    printf("%s\n", S);

    return 0;
}
