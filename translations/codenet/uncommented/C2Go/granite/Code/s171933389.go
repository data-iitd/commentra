
package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

#define max(a,b) ((a) > (b)? (a) : (b))
#define min(a,b) ((a) > (b)? (b) : (a))

func get_int4(a1 *int, a2 *int, a3 *int, a4 *int) int {
    str, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    str = strings.TrimSpace(str)
    strs := strings.Split(str, " ")
    *a1, _ = strconv.Atoi(strs[0])
    *a2, _ = strconv.Atoi(strs[1])
    *a3, _ = strconv.Atoi(strs[2])
    *a4, _ = strconv.Atoi(strs[3])
    return 0
}

func fget_array(arr []int64, size int) {
    for i := 0; i < size; i++ {
        str, _ := bufio.NewReader(os.Stdin).ReadString('\n')
        str = strings.TrimSpace(str)
        arr[i], _ = strconv.ParseInt(str, 10, 64)
    }
}

#define NUM_MAX 1000
#define NUM2_MAX (NUM_MAX*NUM_MAX)
#define RANK_MAX 3000

func asc(a1, a2 int64) bool {
    if a1 > a2 {
        return true
    }
    if a1 == a2 {
        return false
    }
    return false
}

func desc(a1, a2 int64) bool {
    if a1 > a2 {
        return false
    }
    if a1 == a2 {
        return false
    }
    return true
}

#define VAL_MAX (int64)(1e+10)
#define SUM_MAX (VAL_MAX*3)

type range struct {
    start int
    end   int
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
    xrr := make([]int64, x)
    yrr := make([]int64, y)
    zrr := make([]int64, z)
    fget_array(xrr, x)
    fget_array(yrr, y)
    fget_array(zrr, z)
    minSum := VAL_MAX + 1
    maxSum := int64(0)
    for i := 0; i < z; i++ {
        if minSum > zrr[i] {
            minSum = zrr[i]
        }
        if maxSum < zrr[i] {
            maxSum = zrr[i]
        }
    }
    pair := make([]int64, NUM2_MAX)
    idx := 0
    for i := 0; i < x; i++ {
        for j := 0; j < y; j++ {
            pair[idx] = xrr[i] + yrr[j]
            idx++
        }
    }
    sort.Slice(pair, func(i, j int) bool {
        return pair[i] < pair[j]
    })
    minSum += pair[0]
    maxSum += pair[NUM2_MAX-1]
    cache := make([]int, NUM_MAX)
    cntMap := make([]int, NUM_MAX)
    ans := make([]int64, RANK_MAX)
    size := x * y * z
    prev := minSum
    r := rank
    for r >= 1 {
        low := prev - 1
        high := maxSum + 1
        for low + 1 < high {
            mid := (low + high) / 2
            cnt := 0
            for i := 0; i < z; i++ {
                pivot := zrr[i]
                r := range{cache[i] - 1, idx}
                tmp := lower_bound(pair, r, mid-pivot)
                cntMap[i] = tmp
                cnt += tmp
            }
            if cnt <= size-r {
                copy(cache, cntMap)
                low = mid
            } else {
                high = mid
            }
        }
        ans[r-1] = low
        if low == maxSum {
            break
        }
        prev = low
        r--
    }
    for i := 0; i < rank; i++ {
        if ans[i] == 0 {
            ans[i] = maxSum
        }
        fmt.Println(ans[i])
    }
}

