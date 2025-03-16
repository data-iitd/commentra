
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b)? (a) : (b))
#define min(a,b) ((a) > (b)? (b) : (a))

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

#define asc(a1, a2) ((*(int64_t*)a1 > *(int64_t*)a2) - (*(int64_t*)a1 < *(int64_t*)a2))
#define desc(a1, a2) ((*(int64_t*)a1 > *(int64_t*)a2) - (*(int64_t*)a1 < *(int64_t*)a2))

#define lower_bound(arr, r, key) (lower_bound_helper(arr, r, key, asc))

int lower_bound_helper(int64_t *arr, struct range r, int64_t key, int (*comp)(const void*, const void*)) {
    int low = r.start;
    int high = r.end;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(comp(&arr[mid], &key) < 0) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low + 1;
}

int main(void) {
    int x, y, z, rank;
    scanf("%d %d %d %d", &x, &y, &z, &rank);
    int64_t xrr[NUM_MAX];
    int64_t yrr[NUM_MAX];
    int64_t zrr[NUM_MAX];
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);
    int64_t min_sum = VAL_MAX+1;
    int64_t max_sum = 0;
    int i, j;
    for(i = 0; i < z; i++) {
        min_sum = min(min_sum, zrr[i]);
        max_sum += zrr[i];
    }
    int64_t pair[NUM2_MAX];
    int idx = 0;
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            pair[idx++] = xrr[i] + yrr[j];
        }
    }
    qsort(pair, idx, sizeof(int64_t), asc);
    min_sum += pair[0];
    max_sum += pair[idx-1];
    int cache[NUM_MAX];
    int cnt_map[NUM_MAX];
    int64_t ans[RANK_MAX];
    int size = x*y*z;
    int64_t prev = min_sum;
    int r;
    for(r = rank; r >= 1; r--) {
        int64_t low = prev-1;
        int64_t high = max_sum+1;
        while(low + 1 < high) {
            int64_t mid = (low + high)/2;
            for(i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                struct range r = {cache[i]-1, idx};
                int tmp = lower_bound(pair, r, mid-pivot);
                cnt_map[i] = tmp;
            }
            if(sum(cnt_map, z) >= size-r) {
                low = mid;
            } else {
                high = mid;
            }
        }
        ans[r-1] = low;
        if(low == max_sum) break;
        prev = low;
    }
    for(i = 0; i < rank; i++) {
        printf("%lld\n", (ans[i]==0)? max_sum : ans[i]);
    }
    return 0;
}

