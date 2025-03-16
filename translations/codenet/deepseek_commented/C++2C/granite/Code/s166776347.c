
#include <stdio.h>

int main() {
    // 入力
    int N, K;
    scanf("%d %d", &N, &K);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // 解法
    int ans1 = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= j) continue; // Skip if i is not less than j
            if (A[i] > A[j]) ans1++; // Increment ans1 if A[i] > A[j]
        }
    }

    // Count the frequency of each element in the array A
    int count[2005] = {0};
    for (int i = 0; i < N; i++) {
        count[A[i] - 1]++; // Store frequency of A[i]
    }

    int ans2 = 0;
    int remain = N;
    for (int i = 0; i < 2005; i++) {
        remain -= count[i]; // Reduce the remaining count
        ans2 += count[i] * remain; // Calculate the number of valid pairs
    }

    // Calculate the final answer
    int tmp = K * (K - 1);
    tmp /= 2; // Calculate K*(K-1)/2
    tmp *= ans2; // Multiply with ans2
    int ans = 0;
    ans += ans1 * K; // Add contribution from ans1
    ans += tmp; // Add contribution from tmp

    // Output the final answer
    printf("%d\n", ans);

    return 0;
}
