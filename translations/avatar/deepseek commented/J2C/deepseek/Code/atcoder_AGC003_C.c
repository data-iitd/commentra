#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM 100002

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int nums[NUM];
    int indices[NUM];

    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
        indices[i] = nums[i];
    }

    qsort(nums, N, sizeof(int), compare);

    int bin = 0;
    int diff = 0;

    for (int i = 0; i < N; i++) {
        if ((bin % 2) != (indices[i] % 2)) {
            diff++;
        }
        bin++;
        bin %= 2;
    }

    int ans = diff / 2;
    printf("%d\n", ans);

    return 0;
}
