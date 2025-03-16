#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define in(x) scanf("%d", &x)
#define out(str) printf("%s\n", str)

void chmax(int *a, int b) {
 if (*a < b) {
 *a = b;
 }
}

void chmin(int *a, int b) {
 if (b < *a) {
 *a = b;
 }
}

int compare(const void *a, const void *b) {
 return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
 int L, N;
 scanf("%d %d", &N, &L);
 char *S[N];
 rep(i, N) {
 S[i] = (char *)malloc(L + 1);
 scanf("%s", S[i]);
 }
 qsort(S, N, sizeof(char *), compare);
 rep(i, N) {
 printf("%s", S[i]);
 }
 printf("\n");
 rep(i, N) {
 free(S[i]);
 }
}
