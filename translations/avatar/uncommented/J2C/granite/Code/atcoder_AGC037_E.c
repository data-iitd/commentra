
#include <stdio.h>
#include <string.h>

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
        strrev(T);
        char revU[200001];
        strcpy(revU, S);
        strcat(revU, T);
        strrev(revU);
        char sDash[100001];
        strcpy(sDash, S);
        for (int i = N; i >= 0; i -= step) {
            char tmp[100001];
            strncpy(tmp, revU + i, N);
            tmp[N] = '\0';
            if (strcmp(sDash, tmp) > 0) {
                strcpy(sDash, tmp);
            } else {
                if (firstTime) {
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
            step *= 2;
        }
        K--;
        strcpy(S, sDash);
        strrev(S);
    }
    printf("%s\n", S);
    return 0;
}
//END-OF-CODE