
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>

int main() {
    // Initialize variables: N, C, K, t[N], ans, cnt, end
    int N, C, K;
    scanf("%d %d %d", &N, &C, &K);
    int t[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &t[i]);
    }
    int ans = 1;
    int cnt = 1;
    int end = t[0] + K;

    // Sort array t in ascending order
    std::sort(t, t + N);

    // Iterate through array t from index 1 to N-1
    for (int i = 1; i < N; i++) {
        // If counter cnt is less than C and current element t[i] is within the range [end, end+K], increment counter cnt
        if (cnt < C && t[i] <= end) {
            cnt++;
        } else {
            // Reset counter cnt and update end index end to the current element t[i] plus K
            cnt = 1;
            end = t[i] + K;
            // Increment answer counter ans
            ans++;
        }
    }

    // Print the final answer
    printf("%d\n", ans);

    return 0;
}
