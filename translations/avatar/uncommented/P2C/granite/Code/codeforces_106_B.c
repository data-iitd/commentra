
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int S[n], R[n], H[n], C[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &S[i], &R[i], &H[i], &C[i]);
    }
    int outdated[n];
    for (int i = 0; i < n; i++) {
        outdated[i] = 0;
        for (int j = 0; j < n; j++) {
            if (S[i] < S[j] && R[i] < R[j] && H[i] < H[j]) {
                outdated[i] = 1;
                break;
            }
        }
    }
    int minimum_cost = 100000;
    int input_number = 0;
    for (int i = 0; i < n; i++) {
        if (outdated[i] == 0 && C[i] < minimum_cost) {
            minimum_cost = C[i];
            input_number = i + 1;
        }
    }
    printf("%d\n", input_number);
    return 0;
}
