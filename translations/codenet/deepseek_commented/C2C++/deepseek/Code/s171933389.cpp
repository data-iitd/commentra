#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

struct range {
    int start;
    int end;
};

int get_int4(int *a1, int *a2, int *a3, int *a4) {
  std::cin >> *a1 >> *a2 >> *a3 >> *a4;
  return 0;
}

int fget_array(std::vector<int64_t> &arr, int size) {
    arr.resize(size);
    for(int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }
    return 0;
}

int asc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return 1;
    if(aa1 == aa2) return 0;
    return -1;
}

int desc(const void *a1, const void *a2) {
    int64_t aa1 = *(int64_t*)a1;
    int64_t aa2 = *(int64_t*)a2;
    if(aa1 > aa2) return -1;
    if(aa1 == aa2) return 0;
    return 1;
}

int lower_bound(std::vector<int64_t> &arr, struct range r, int64_t key) {
    int low = r.start;;
    int high = r.end;
    while(low + 1 < high) {
        int mid = (low + high) / 2;
        if(arr[mid] < key) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return low + 1;
}

int main(void) {
    int x, y, z, rank;
    get_int4(&x, &y, &z, &rank);
    std::vector<int64_t> xrr(NUM_MAX);
    std::vector<int64_t> yrr(NUM_MAX);
    std::vector<int64_t> zrr(NUM_MAX);
    fget_array(xrr, x);
    fget_array(yrr, y);
    fget_array(zrr, z);
    int64_t min_sum = VAL_MAX+1;
    int64_t max_sum = 0;
    for(int i = 0; i < z; i++) min_sum = min(min_sum, zrr[i]);
    for(int i = 0; i < z; i++) max_sum = max(max_sum, zrr[i]);

    std::vector<int64_t> pair(NUM2_MAX);
    int idx = 0;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            pair[idx++] = xrr[i] + yrr[j];
        }
    }
    std::sort(pair.begin(), pair.begin() + idx, std::less<int64_t>());
    min_sum += pair[0];
    max_sum += pair[idx-1];

    std::vector<int> cache(NUM_MAX);
    std::vector<int> cnt_map(NUM_MAX);
    std::vector<int64_t> ans(RANK_MAX);
    int size = x*y*z;
    int64_t prev = min_sum;
    int r;
    for(r = rank; r >= 1; r--) {
        int64_t low = prev-1;
        int64_t high = max_sum+1;
        while(low + 1 < high) {
            int64_t mid = (low + high)/2;
            int cnt = 0;
            for(int i = 0; i < z; i++) {
                int64_t pivot = zrr[i];
                struct range r = {cache[i]-1, idx};
                int tmp = lower_bound(pair, r, mid-pivot);
                cnt_map[i] = tmp;
                cnt += tmp;
            }
            if(cnt <= size-r) {
                std::copy(cnt_map.begin(), cnt_map.begin() + z, cache.begin());
                low = mid;
            } else {
                high = mid;
            }
        }
        ans[r-1] = low;
        if(low == max_sum) break;
        prev = low;
    }
    for(int i = 0; i < rank; i++) {
        std::cout << (ans[i]==0 ? max_sum : ans[i]) << std::endl;
    }

    return 0;
}
