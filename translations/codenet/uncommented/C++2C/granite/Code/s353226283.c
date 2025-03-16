
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int main() {
    int n, k, t;
    int *vec;
    int ans = 1000000001;
    scanf("%d %d", &n, &k);
    vec = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        vec[i] = t;
    }
    std::sort(vec, vec + n);
    for (int i = 0; i + k -1 < n; i++) {
        int diff = vec[i+k-1] - vec[i];
        if (diff < ans) {
            ans = diff;
        }
    }
    printf("%d\n", ans);
    free(vec);
    return 0;
}
