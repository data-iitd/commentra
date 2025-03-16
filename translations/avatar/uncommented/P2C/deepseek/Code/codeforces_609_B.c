#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &lst[i]);
    }
    int l[100001] = {0}; // Assuming the maximum value in lst is 100000
    for (int i = 0; i < n; i++) {
        l[lst[i]]++;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (l[lst[i]] > 1) {
            res += n - i - l[lst[i]];
            l[lst[i]]--;
        } else {
            res += n - i - 1;
        }
    }
    printf("%d\n", res);
    return 0;
}
