// The code starts by including necessary headers for input/output operations, string manipulation, and memory management.
<<<<<<< HEAD

import (
=======
package main

import (
    "bufio"
>>>>>>> 98c87cb78a (data updated)
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Macros are defined to set the maximum sizes for arrays and other constants.
const (
    NUM_MAX = 1000
    NUM2_MAX = NUM_MAX * NUM_MAX
    RANK_MAX = 3000
)

// This function reads four integers from the standard input and stores them in the provided variables.
func get_int4(a1 *int, a2 *int, a3 *int, a4 *int) {
    fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
}

// This function reads an array of integers from the standard input.
func fget_array(arr []int64, size int) {
    for i := 0; i < size; i++ {
        fmt.Scanf("%d", &arr[i])
    }
}

// These functions are used to compare integers for sorting in ascending and descending order.
func asc(a1, a2 interface{}) bool {
    aa1 := a1.(int64)
    aa2 := a2.(int64)
    return aa1 < aa2
}

func desc(a1, a2 interface{}) bool {
    aa1 := a1.(int64)
    aa2 := a2.(int64)
    return aa1 > aa2
}

// Constants are defined for the maximum values of various quantities.
const (
    VAL_MAX = 1e+10
    SUM_MAX = VAL_MAX * 3
)

// A structure is defined to represent a range of indices.
type range struct {
    start int
    end   int
}

// This function finds the lower bound of a key in a sorted array within a given range.
func lower_bound(arr []int64, r range, key int64) int {
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

// The main function reads input, processes data, and outputs the result based on the given rank.
func main() {
    var x, y, z, rank int
    get_int4(&x, &y, &z, &rank)
    var xrr [NUM_MAX]int64
    var yrr [NUM_MAX]int64
    var zrr [NUM_MAX]int64
    fget_array(xrr[:], x)
    fget_array(yrr[:], y)
    fget_array(zrr[:], z)
    min_sum := VAL_MAX + 1
    max_sum := 0
    for i := 0; i < z; i++ {
        min_sum = min(min_sum, zrr[i])
        max_sum = max(max_sum, zrr[i])
    }
    var pair [NUM2_MAX]int64
    idx := 0
    for i := 0; i < x; i++ {
        for j := 0; j < y; j++ {
            pair[idx] = xrr[i] + yrr[j]
            idx++
        }
    }
    sort.Slice(pair[:idx], asc)
    min_sum += pair[0]
    max_sum += pair[idx-1]
    var cache [NUM_MAX]int
    var cnt_map [NUM_MAX]int
    var ans [RANK_MAX]int64
    size := x * y * z
    prev := min_sum
    for r := rank; r >= 1; r-- {
        low := prev - 1
        high := max_sum + 1
        for low+1 < high {
            mid := (low + high) / 2
            cnt := 0
            for i := 0; i < z; i++ {
                pivot := zrr[i]
                r := range{cache[i]-1, idx}
                tmp := lower_bound(pair[:idx], r, mid-pivot)
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
    for i := 0; i < rank; i++ {
        fmt.Printf("%d\n", ans[i])
    }
}

