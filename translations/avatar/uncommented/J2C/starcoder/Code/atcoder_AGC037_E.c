#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int N, K;
    char S[100000];
    scanf("%d %d", &N, &K);
    scanf("%s", S);
    int step = 1;
    while (K > 0) {
        char T[100000];
        strcpy(T, S);
        int i;
        for (i = 0; i < N; i++) {
            T[i] = S[N - 1 - i];
        }
        char U[100000];
        strcpy(U, S);
        strcat(U, T);
        char sDash[100000];
        strcpy(sDash, S);
        int firstTime = 1;
        for (i = N; i >= 0; i -= step) {
            char tmp[100000];
            strcpy(tmp, U + i);
            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                if (firstTime == 0) {
                    break;
                }
            }
        }
        if (firstTime) {
            if (pow(2, K) > N) {
                printf("%c", sDash[0]);
                for (i = 1; i < N; i++) {
                    printf("%c", sDash[i]);
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
    printf("%s\n", S);
    return 0;
}

