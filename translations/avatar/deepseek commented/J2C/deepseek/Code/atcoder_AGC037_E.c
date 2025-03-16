#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, K;
    char S[1000];
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    char T[1000];
    strcpy(T, S);
    int step = 1;
    int firstTime = 1;

    while (K > 0) {
        char revU[2000];
        strcpy(revU, S);
        strcat(revU, strrev(T));
        strrev(revU);
        char sDash[1000];
        strcpy(sDash, S);

        for (int i = N; i >= 0; i -= step) {
            char tmp[1000];
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
        strrev(S);
    }
    strrev(S);
    printf("%s\n", S);
    return 0;
}

