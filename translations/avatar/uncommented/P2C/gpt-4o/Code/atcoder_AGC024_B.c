#include <stdio.h>

void editorial(int N, int P[]) {
    if (N == 1) {
        printf("0\n");
        return;
    }
    
    int a[N + 1];
    for (int i = 0; i <= N; i++) {
        a[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        a[P[i]] = i;
    }
    
    int tmp = 1;
    int max_len = 1;
    for (int i = 1; i < N; i++) {
        if (a[i] < a[i + 1]) {
            tmp += 1;
            if (tmp > max_len) {
                max_len = tmp;
            }
        } else {
            tmp = 1;
        }
    }
    
    int ans = N - max_len;
    printf("%d\n", ans);
}

void WA(int N, int P[]) {
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (i == 0 || P[i - 1] + 1 == P[i]) {
            tmp += 1;
        } else {
            if (ans < tmp) {
                ans = tmp;
            }
            tmp = 1;
        }
    }
    printf("%d\n", N - ans);
}

int main() {
    int N;
    scanf("%d", &N);
    int P[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i]);
    }
    editorial(N, P);
    // WA(N, P); // Uncomment this line if you want to call the WA function
    return 0;
}

// <END-OF-CODE>
