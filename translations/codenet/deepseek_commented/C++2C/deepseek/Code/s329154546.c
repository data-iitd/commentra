#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define in(x) scanf("%d", &x)
#define out(str) printf("%s\n", str)

typedef long long ll;

int compare(const void *a, const void *b) {
    char *str1 = *(char **)a;
    char *str2 = *(char **)b;
    return strcmp(str1, str2);
}

int L, N;

int main() {
    in(N); in(L);
    char *S[N];
    rep(i, N) {
        S[i] = (char *)malloc(L + 1);
        scanf("%s", S[i]);
    }
    qsort(S, N, sizeof(char *), compare);
    rep(i, N) {
        printf("%s", S[i]);
        if (i < N - 1) printf(" ");
    }
    printf("\n");
    rep(i, N) free(S[i]);
}
