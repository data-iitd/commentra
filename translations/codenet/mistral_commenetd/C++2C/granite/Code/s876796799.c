
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    int ind_a[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &ind_a[i]);
    }
    int used_inds[N];
    memset(used_inds, 0, sizeof(used_inds));
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int left_border = -1;
        int right_border = N;
        int cur_ind = ind_a[i];
        int left_it = 0;
        int right_it = 0;
        while (left_it < N && used_inds[left_it]!= 0) {
            left_it++;
        }
        if (left_it < N && used_inds[left_it] == 0) {
            left_it++;
        }
        while (right_it < N && used_inds[right_it]!= 0) {
            right_it++;
        }
        if (right_it < N && used_inds[right_it] == 0) {
            right_it++;
        }
        while (left_it < N && used_inds[left_it] <= cur_ind) {
            left_it++;
        }
        if (left_it < N && used_inds[left_it] > cur_ind) {
            left_it--;
        }
        left_border = left_it;
        while (right_it < N && used_inds[right_it] < cur_ind) {
            right_it++;
        }
        right_border = right_it;
        ans += (long long)(cur_ind - left_border) * (right_border - cur_ind) * (i + 1);
        used_inds[cur_ind] = 1;
    }
    printf("%lld\n", ans);
    return 0;
}
