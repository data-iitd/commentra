#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    long long H[N];
    int ans[N];
    for (int i = 0; i < N; i++) {
        scanf("%lld", &H[i]);
        ans[i] = 1; // Initially assuming that all elements are in the left half
    }

    for (int query = 0; query < M; query++) {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);

        if (H[temp1 - 1] < H[temp2 - 1]) {
            ans[temp1 - 1] = 0; // The first index cannot be in the left half
        } else if (H[temp1 - 1] > H[temp2 - 1]) {
            ans[temp2 - 1] = 0; // The second index cannot be in the left half
        } else {
            ans[temp1 - 1] = 0; // Both the first and second indices cannot be in the left half
            ans[temp2 - 1] = 0;
        }
    }

    int ans2 = 0; // Initializing a counter to store the number of elements in the left half
    for (int i = 0; i < N; i++) {
        if (ans[i]) { // If an element is still assumed to be in the left half
            ans2++; // Increment the counter
        }
    }

    printf("%d\n", ans2); // Printing the final answer
    return 0;
}
