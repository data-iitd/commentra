#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int solve() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] <= arr[0]) {
            sum++;
        }
    }

    return sum;
}

int main() {
    printf("%d\n", solve());
    return 0;
}
