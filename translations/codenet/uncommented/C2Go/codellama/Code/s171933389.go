#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h> // uint64_t

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

func get_int4(a1, a2, a3, a4 *int) {
  fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
  return 0
}

// <arr[0]> <arr[1]> .. <arr[size-1]>
func fget_array(arr []int64, size int) {
    for i := 0; i < size; i++ {
        fmt.Scanf("%lld", &arr[i])
    }
    return 0
}

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

func asc(a1, a2 unsafe.Pointer) int {
    aa1 := *(*int64)(a1)
    aa2 := *(*int64)(a2)
    if aa1 > aa2 {
        return 1
    }
    if aa1 == aa2 {
        return 0
    }
    return -1
}

func desc(a1, a2 unsafe.Pointer) int {
    aa1 := *(*int64)(a1)
    aa2 := *(*int64)(a2)
    if aa1 > aa2 {
        return -1
    }
    if aa1 == aa2 {
        return 0
    }
    return 1
}

#define VAL_MAX (int64_t)(1e+10)
#define SUM_MAX (VAL_MAX*3)

type range struct {
    start int
    end int
}
func lower_bound(arr []int64, r range, key int64) int {
    low := r.start
    high := r.end
    for low + 1 < high {
        mid := (low + high) / 2
        if arr[mid] < key {
            low = mid
        } else {
            high = mid
        }
    }
    return low + 1
}

func main() {
    var x, y, z, rank int
    get_int4(&x, &y, &z, &rank)
    var xrr [NUM_MAX]int64
    var yrr [NUM_MAX]int64
    var zrr [NUM_MAX]int64
    fget_array(xrr[:], x)
    fget_array(yrr[:], y)
    fget_array(zrr[:], z)
    var min_sum int64 = VAL_MAX+1
    var max_sum int64 = 0
    var i, j int
    for i = 0; i < z; i++ {
        min_sum = min(min_sum, zrr[i])
    }
    for i = 0; i < z; i++ {
        max_sum = max(max_sum, zrr[i])
    }

    var pair [NUM2_MAX]int64
    idx := 0
    for i = 0; i < x; i++ {
        for j = 0; j < y; j++ {
            pair[idx] = xrr[i] + yrr[j]
            idx++
        }
    }
    qsort(unsafe.Pointer(&pair[0]), uintptr(idx), unsafe.Sizeof(int64(0)), asc)
    min_sum += pair[0]
    max_sum += pair[idx-1]

    var cache [NUM_MAX]int
    var cnt_map [NUM_MAX]int
    var ans [RANK_MAX]int64
    size := x*y*z
    var prev int64 = min_sum
    var r int
    for r = rank; r >= 1; r-- {
        var low int64 = prev-1
        var high int64 = max_sum+1
        for low + 1 < high {
            var mid int64 = (low + high)/2
            var cnt int = 0
            for i = 0; i < z; i++ {
                var pivot int64 = zrr[i]
                r := range{cache[i]-1, idx}
                tmp := lower_bound(pair[:], r, mid-pivot)
                cnt_map[i] = tmp
                cnt += tmp
            }
            if cnt <= size-r {
                copy(cache[:], cnt_map[:])
                low = mid
            } else {
                high = mid
            }
        }
        ans[r-1] = low
        if low == max_sum {
            break
        }
        prev = low
    }
    for i = 0; i < rank; i++ {
        fmt.Printf("%lld\n", (ans[i]==0) ? max_sum : ans[i])
    }

    return 0
}

