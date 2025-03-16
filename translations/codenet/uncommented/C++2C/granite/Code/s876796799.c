
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <assert.h>

int main(int argc, char **argv)
{
    int N;
    scanf("%d", &N);
    long long a[200000];
    int ind_a[200000];
    for(int i = 0; i < N; i++){
        scanf("%lld", &a[i]);
    }
    for(int i = 0; i < N; i++){
        ind_a[a[i] - 1] = i;
    }

    int used_inds[200000];
    int used_inds_size = 0;
    long long ans = 0;
    for(int i = 0; i < N; i++){
        int left_border;
        int right_border;
        int cur_ind = ind_a[i];
        int left_it = 0;
        int right_it = 0;
        while(left_it < used_inds_size && used_inds[left_it] < cur_ind) left_it++;
        if(left_it == 0) left_border = -1;
        else left_border = used_inds[left_it - 1];
        while(right_it < used_inds_size && used_inds[right_it] <= cur_ind) right_it++;
        if(right_it == used_inds_size) right_border = N;
        else right_border = used_inds[right_it];
        ans += (cur_ind - left_border) * (right_border - cur_ind) * ((long long)i + 1);
        used_inds[used_inds_size++] = cur_ind;
    }

    printf("%lld\n", ans);
    return 0;
}
