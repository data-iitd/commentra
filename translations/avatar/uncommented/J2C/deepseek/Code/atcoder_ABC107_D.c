#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);
    ll total = (ll)N * (N + 1) / 2;
    int l = 0, r = N - 1;
    while (l < r) {
        int mid = l + (r - l) / 2;
        int target = arr[mid];
        int cur = 0;
        ll cnt = 0;
        int bit[2 * N + 2];
        memset(bit, 0, sizeof(bit));
        for (int x = N + 1; x < 2 * N + 2; x += x & -x) bit[x]++;
        for (int i = 0; i < N; i++) {
            cur += arr[i] <= target ? 1 : -1;
            for (int x = cur + N + 1; x < 2 * N + 2; x += x & -x) bit[x]++;
            for (int x = cur + N; x > 0; x -= x & -x) cnt += bit[x];
        }
        if (cnt >= total / 2 + 1) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", arr[l]);
    return 0;
}
