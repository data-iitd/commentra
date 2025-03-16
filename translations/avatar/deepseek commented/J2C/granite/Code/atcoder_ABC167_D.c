

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <assert.h>

int main() {
    // Read the number of elements N and the value K
    int N, K;
    scanf("%d %d", &N, &K);

    // Read the array A with N elements, adjusting each element by -1 for 0-based indexing
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        A[i]--;
    }

    // Set to track visited indices
    bool used[N];
    memset(used, 0, sizeof(used));

    // Arrays to store index and position information
    int idx[N];
    int pos[N];

    // Initialize variables for cycle detection
    int next = 0, cur = 0;

    // Detect the cycle in the array A
    while (!used[next]) {
        used[next] = true;
        idx[next] = cur;
        pos[cur] = next;
        next = A[next];
        cur++;
    }

    // Calculate the length of the cycle and adjust the position based on K
    long long a = (long long)cur - idx[next];
    long long b = (long long)idx[next];
    int ans = (int)((10000 * a + K - b) % a + b);

    // Adjust the answer if necessary based on the cycle length
    if (b > K) ans = K;

    // Output the final position
    printf("%d\n", pos[ans] + 1);

    return 0;
}

