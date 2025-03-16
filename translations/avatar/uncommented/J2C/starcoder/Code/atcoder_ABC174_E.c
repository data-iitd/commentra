#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int logsLength[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &logsLength[i]);
    }
    int min = 1, max = 1000000001;
    while (min < max) {
        int mid = (min + max) / 2;
        if (nei(mid, logsLength, k)) {
            max = mid;
        } else {
            min = mid + 1;
        }
    }
    printf("%d\n", min);
    return 0;
}

bool nei(int mid, int logsLength[], int k) {
    for (int i = 0; i < n; i++) {
        k -= (logsLength[i] + mid - 1) / mid - 1;
        if (k < 0) {
            return false;
        }
    }
    return true;
}

