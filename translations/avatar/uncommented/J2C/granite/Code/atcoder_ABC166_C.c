
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    long H[N];
    int ans[N];
    for (int i = 0; i < N; i++) {
        scanf("%ld", &H[i]);
        ans[i] = 1;
    }
    for (int i = 0; i < M; i++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = 0;
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = 0;
        } else {
            ans[temp1 - 1] = 0;
            ans[temp2 - 1] = 0;
        }
    }
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
        ans2 += ans[i];
    }
    printf("%d\n", ans2);
    return 0;
}
// 