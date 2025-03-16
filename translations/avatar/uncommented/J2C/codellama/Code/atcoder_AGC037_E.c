#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main ( ) {
    int N, K;
    char *sDash;
    int step = 1;
    int i;
    int firstTime = 1;
    char c;

    scanf("%d %d", &N, &K);
    sDash = (char *) malloc(N * sizeof(char));
    scanf("%s", sDash);

    while (K > 0) {
        char *revU = (char *) malloc((N * 2) * sizeof(char));
        strcpy(revU, sDash);
        strcat(revU, sDash);
        strrev(revU);

        if (firstTime) {
            if (pow(2, K) > N) {
                c = sDash[0];
                for (i = 0; i < N; i++) {
                    printf("%c", c);
                }
                printf("\n");
                free(sDash);
                free(revU);
                return 0;
            }
        }

        for (i = N; i >= 0; i -= step) {
            char *tmp = (char *) malloc(N * sizeof(char));
            strncpy(tmp, revU + i, N);
            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                if (!firstTime) {
                    break;
                }
            }
            free(tmp);
        }

        if (firstTime) {
            firstTime = 0;
            step += step;
        }

        K--;
        free(revU);
    }

    printf("%s\n", sDash);
    free(sDash);

    return 0;
}

