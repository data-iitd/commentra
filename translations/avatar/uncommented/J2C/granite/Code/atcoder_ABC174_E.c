
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int logsLength[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]);
    }
    int min = 1, max = 100000000;
    while (min < max) {
        int mid = (min + max) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            count += (logsLength[i] + mid - 1) / mid - 1;
        }
        if (count <= k) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    printf("%d\n", min);
    return 0;
}
// END-OF-CODE