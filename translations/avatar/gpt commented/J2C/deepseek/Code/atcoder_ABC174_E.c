#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nei(int mid, int logsLength[], int k, int n) {
    int totalCuts = 0;
    for (int i = 0; i < n; ++i) {
        totalCuts += (logsLength[i] + mid - 1) / mid - 1;
    }
    return totalCuts <= k;
}

void solve(int n, int k, int logsLength[]) {
    int min = 1, max = 1e9 + 1000;
    while (min < max) {
        int mid = (min + max) / 2;
        if (nei(mid, logsLength, k, n)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    printf("%d\n", min);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int logsLength[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &logsLength[i]);
    }
    solve(n, k, logsLength);
    return 0;
}

