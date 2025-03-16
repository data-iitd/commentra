#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int V[N], C[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", &C[i]);
    }
    
    int list[N + 1];
    list[0] = 0;
    int ans = 0;
    
    for (int i = 0; i < N; i++) {
        if (V[i] - C[i] > 0) {
            list[i + 1] = V[i] - C[i];
        } else {
            list[i + 1] = 0;
        }
    }
    
    for (int i = 0; i <= N; i++) {
        ans += list[i];
    }
    
    printf("%d\n", ans);
    
    return 0;
}
