#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repi(i,a,b) for(int i = (a); i < (b); i++)
#define in(x) scanf("%d", &x)
#define out(str) printf("%s\n", str)

void chmax(int *a, const int *b) {
    if (*a < *b) {
        *a = *b;
    }
}

void chmin(int *a, const int *b) {
    if (*b < *a) {
        *a = *b;
    }
}

int main() {
    int L, N;
    scanf("%d %d", &N, &L);
    char S[N][L+1];
    rep(i, N) {
        scanf("%s", S[i]);
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(S[i], S[j]) > 0) {
                char temp[L+1];
                strcpy(temp, S[i]);
                strcpy(S[i], S[j]);
                strcpy(S[j], temp);
            }
        }
    }
    rep(i, N) {
        printf("%s", S[i]);
    }
    printf("\n");
}
