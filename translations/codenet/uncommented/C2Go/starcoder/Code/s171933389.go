package main

import (
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

func main() {
    var x, y, z, rank int
    fmt.Scanf("%d %d %d %d", &x, &y, &z, &rank)
    xrr := make([]int64, x)
    yrr := make([]int64, y)
    zrr := make([]int64, z)
    for i := 0; i < x; i++ {
        fmt.Scanf("%d", &xrr[i])
    }
    for i := 0; i < y; i++ {
        fmt.Scanf("%d", &yrr[i])
    }
    for i := 0; i < z; i++ {
        fmt.Scanf("%d", &zrr[i])
    }
    min_sum := int64(1e+10)
    max_sum := int64(0)
    for i := 0; i < z; i++ {
        min_sum = min(min_sum, zrr[i])
        max_sum = max(max_sum, zrr[i])
    }
    pair := make([]int64, x*y)
    idx := 0
    for i := 0; i < x; i++ {
        for j := 0; j < y; j++ {
            pair[idx] = xrr[i] + yrr[j]
            idx++
        }
    }
    sort.Slice(pair, func(i, j int) bool { return pair[i] < pair[j] })
    min_sum += pair[0]
    max_sum += pair[len(pair)-1]
    cache := make([]int, z)
    cnt_map := make([]int, z)
    ans := make([]int64, rank)
    size := x*y*z
    prev := min_sum
    for r := rank; r >= 1; r-- {
        low := prev - 1
        high := max_sum + 1
        for low+1 < high {
            mid := (low + high) / 2
            cnt := 0
            for i := 0; i < z; i++ {
                pivot := zrr[i]
                r := struct {
                    start int
                    end   int
                }{cache[i]-1, idx}
                tmp := lower_bound(pair, r, mid-pivot)
                cnt_map[i] = tmp
                cnt += tmp
            }
            if cnt <= size-r {
                copy(cache, cnt_map)
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
    for i := 0; i < rank; i++ {
        fmt.Printf("%d\n", ans[i])
    }
}

func min(a, b int64) int64 {
    if a < b {
        return a
    }
    return b
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

func lower_bound(arr []int64, r struct{ start, end int }, key int64) int {
    low := r.start
    high := r.end
    for low+1 < high {
        mid := (low + high) / 2
        if arr[mid] < key {
            low = mid
        } else {
            high = mid
        }
    }
    return low + 1
}

