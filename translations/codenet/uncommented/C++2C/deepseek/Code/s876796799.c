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

    int *used_inds = (int*)malloc(N * sizeof(int));
    int used_inds_size = 0;
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long left_border;
        long long right_border;
        int cur_ind = ind_a[i];
        int *left_it = used_inds;
        int *right_it = used_inds;

        while (left_it < used_inds + used_inds_size && *left_it < cur_ind) {
            left_it++;
        }
        while (right_it < used_inds + used_inds_size && *right_it <= cur_ind) {
            right_it++;
        }

        if (left_it == used_inds) {
            left_border = -1;
        } else {
            left_border = *(left_it - 1);
        }
        if (right_it == used_inds + used_inds_size) {
            right_border = N;
        } else {
            right_border = *right_it;
        }
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);

        //printf("%d %lld %lld\n", i, left_border, right_border);
        //printf("%lld\n", ans);

        used_inds[used_inds_size++] = cur_ind;
        qsort(used_inds, used_inds_size, sizeof(int), compare);
    }

    printf("%lld\n", ans);
    free(used_inds);
    return 0;
}
