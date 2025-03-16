#include <stdio.h>
#include <stdbool.h>

int main() {
    int N;
    long M;
    scanf("%d", &N);
    scanf("%ld", &M);
    
    long H[N];
    bool ans[N];
    
    for (int i = 0; i < N; i++) {
        scanf("%ld", &H[i]);
        ans[i] = true;
    }
    
    for (long i = 0; i < M; i++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = false;
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = false;
        } else {
            ans[temp1 - 1] = false;
            ans[temp2 - 1] = false;
        }
    }
    
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        if (ans[i]) {
            ans2++;
        }
    }
    
    printf("%d\n", ans2);
    
    return 0;
}

// <END-OF-CODE>
