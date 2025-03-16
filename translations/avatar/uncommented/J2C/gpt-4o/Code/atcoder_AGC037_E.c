#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    char *S = (char *)malloc((N + 1) * sizeof(char));
    scanf("%s", S);
    
    int firstTime = 1;
    int step = 1;

    while (K > 0) {
        char *T = (char *)malloc((N + 1) * sizeof(char));
        for (int i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        T[N] = '\0';

        char *revU = (char *)malloc((2 * N + 1) * sizeof(char));
        strcpy(revU, S);
        strcat(revU, T);
        
        // Reverse revU
        for (int i = 0; i < 2 * N / 2; i++) {
            char temp = revU[i];
            revU[i] = revU[2 * N - 1 - i];
            revU[2 * N - 1 - i] = temp;
        }

        char *sDash = (char *)malloc((N + 1) * sizeof(char));
        strcpy(sDash, S);

        for (int i = N; i >= 0; i -= step) {
            char tmp[N + 1];
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
                free(S);
                free(T);
                free(revU);
                free(sDash);
                return 0;
            }
        } else {
            step += step;
        }
        K--;
        free(S);
        S = (char *)malloc((N + 1) * sizeof(char));
        strcpy(S, sDash);
        // Reverse S
        for (int i = 0; i < N / 2; i++) {
            char temp = S[i];
            S[i] = S[N - 1 - i];
            S[N - 1 - i] = temp;
        }
        free(T);
        free(revU);
        free(sDash);
    }

    printf("%s\n", S);
    free(S);
    return 0;
}

// <END-OF-CODE>
