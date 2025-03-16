#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int S[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
    }
    
    int temp = 0;
    int ans = 1000000000;

    if (K == 1) {
        for (int i = 0; i < N; i++) {
            temp = S[i];
            ans = temp < 0 ? (temp < 0 ? temp : -temp) : (temp > 0 ? temp : -temp);
        }
        printf("%d\n", ans);
    } else if (N - K != 0) {
        for (int i = 0; i <= N - K; i++) {
            int min = S[i];
            int max = S[i + K - 1];
            
            if (min < 0 && max > 0) {
                temp = min < 0 ? (2 * (-min) + max) : ((-min) + 2 * max);
            } else {
                temp = min < 0 ? -min : min;
                temp = max > temp ? max : temp;
            }
            
            ans = ans < temp ? ans : temp;
        }
        printf("%d\n", ans);
    } else {
        int min = S[0];
        int max = S[N - 1];
        
        if (min < 0 && max > 0) {
            printf("%d\n", min < 0 ? (2 * (-min) + max) : ((-min) + 2 * max));
        } else {
            printf("%d\n", min < 0 ? -min : min);
            printf("%d\n", max > min ? max : min);
        }
    }
    
    return 0;
}
