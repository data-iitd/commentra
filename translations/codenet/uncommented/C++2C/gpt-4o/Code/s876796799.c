#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long a[200000];
int ind_a[200000];

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &a[i]);
    }
    for (int i = 0; i < N; i++) {
        ind_a[a[i] - 1] = i;
    }

    int *used_inds = (int *)malloc(N * sizeof(int));
    int used_count = 0;
    long long ans = 0;

    for (int i = 0; i < N; i++) {
        long long left_border;
        long long right_border;
        long long cur_ind = ind_a[i];

        // Find left border
        int left_it = -1;
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] < cur_ind) {
                left_it = j;
            } else {
                break;
            }
        }
        left_border = (left_it == -1) ? -1 : used_inds[left_it];

        // Find right border
        int right_it = used_count;
        for (int j = 0; j < used_count; j++) {
            if (used_inds[j] > cur_ind) {
                right_it = j;
                break;
            }
        }
        right_border = (right_it == used_count) ? N : used_inds[right_it];

        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

        // Insert current index into used_inds
        used_inds[used_count++] = cur_ind;
        qsort(used_inds, used_count, sizeof(int), compare);
    }

    printf("%lld\n", ans);
    free(used_inds);
    return 0;
}

// <END-OF-CODE>
