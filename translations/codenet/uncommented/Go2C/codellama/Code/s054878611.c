#include <stdio.h>

int solution(int n, int a[]) {
        int memo[100002] = {0};
        for (int i = 0; i < n; i++) {
                memo[a[i]]++;
                memo[a[i] + 1]++;
                memo[a[i] + 2]++;
        }
        int out = 0;
        for (int i = 0; i < 100002; i++) {
                if (memo[i] > 0) {
                        out = (out > memo[i]) ? out : memo[i];
                }
        }
        return out;
}

int main() {
        int n;
        scanf("%d", &n);
        int a[n];
        for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
        }
        printf("%d\n", solution(n, a));
        return 0;
}

