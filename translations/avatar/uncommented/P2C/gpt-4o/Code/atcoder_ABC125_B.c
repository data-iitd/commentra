#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int V[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &V[i]);
    }
    
    int C[N];
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
            list[i + 1] = 0; // Ensure we have a value even if the condition is not met
        }
    }
    
    for (int i = 0; i <= N; i++) {
        ans += list[i];
    }
    
    printf("%d\n", ans);
    
    return 0;
}

// <END-OF-CODE>
