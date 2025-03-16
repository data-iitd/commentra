#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_same(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[0]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int elems[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &elems[i]);
    }

    if (all_same(elems, n)) {
        printf("0\n");
        return 0;
    }

    if (k == 1) {
        printf("-1\n");
        return 0;
    }

    if (!all_same(elems + k - 1, n - k + 1)) {
        printf("-1\n");
        return 0;
    }

    int target = elems[n - 1];
    int to_delete[n];
    int count = 0;
    for (int i = 0; i < k - 1; i++) {
        to_delete[count++] = elems[i];
    }

    while (count > 0 && to_delete[count - 1] == target) {
        count--;
    }

    printf("%d\n", count);
    return 0;
}
