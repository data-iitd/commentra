#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int n, int* a);

int main(int argc, char* argv[]) {
        int n;
        scanf("%d", &n);
        int* a = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
        }
        printf("%d\n", solution(n, a));
        free(a);
        return 0;
}

int solution(int n, int* a) {
        int* memo = (int*)malloc((1e5 + 2) * sizeof(int));
        memset(memo, 0, (1e5 + 2) * sizeof(int));
        for (int i = 0; i < n; i++) {
                memo[a[i]]++;
                memo[a[i] + 1]++;
                memo[a[i] + 2]++;
        }
        int out = 0;
        for (int i = 0; i < (1e5 + 2); i++) {
                if (memo[i] > 0) {
                        out = max(out, memo[i]);
                }
        }
        free(memo);
        return out;
}

int max(int x, int y) {
        if (x > y) {
                return x;
        }
        return y;
}

