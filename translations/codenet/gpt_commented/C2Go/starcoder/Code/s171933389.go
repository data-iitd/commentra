package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Constants defining maximum sizes for arrays and ranks
const (
    NUM_MAX = 1000
    NUM2_MAX = NUM_MAX * NUM_MAX
    RANK_MAX = 3000
)

// Comparison function for ascending order used in qsort
func asc(a1, a2 interface{}) bool {
    aa1 := a1.(int64)
    aa2 := a2.(int64)
    return aa1 < aa2
}

// Comparison function for descending order used in qsort
func desc(a1, a2 interface{}) bool {
    aa1 := a1.(int64)
    aa2 := a2.(int64)
    return aa1 > aa2
}

// Constants defining maximum values for calculations
const (
    VAL_MAX = 1e+10
    SUM_MAX = VAL_MAX * 3
)

// Structure to represent a range with start and end indices
type range struct {
    start int
    end   int
}

// Function to find the lower bound index of a key in a sorted array
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
    return low + 1 // Return the index of the first element greater than key
}

// Function to read four integers from standard input
func get_int4(a1, a2, a3, a4 *int) {
    fmt.Scanf("%d %d %d %d", a1, a2, a3, a4)
}

// Function to read an array of int64_t from standard input
func fget_array(arr []int64, size int) {
    for i := 0; i < size; i++ {
        fmt.Scanf("%d", &arr[i])
    }
}

// Main function
func main() {
    // Variables to hold input values and rank
    var x, y, z, rank int
    get_int4(&x, &y, &z, &rank) // Read the dimensions and rank

    // Arrays to hold input values
    xrr := make([]int64, x)
    yrr := make([]int64, y)
    zrr := make([]int64, z)

    // Read the arrays from input
    fget_array(xrr, x)
    fget_array(yrr, y)
    fget_array(zrr, z)

    // Initialize min and max sums
    min_sum := VAL_MAX + 1
    max_sum := 0

    // Calculate minimum and maximum values from zrr
    for i := 0; i < z; i++ {
        min_sum = min(min_sum, zrr[i])
        max_sum = max(max_sum, zrr[i])
    }

    // Create an array to hold the sums of pairs from xrr and yrr
    pair := make([]int64, NUM2_MAX)
    idx := 0

    // Calculate all possible sums of pairs from xrr and yrr
    for i := 0; i < x; i++ {
        for j := 0; j < y; j++ {
            pair[idx] = xrr[i] + yrr[j]
            idx++
        }
    }

    // Sort the pair array in ascending order
    sort.Slice(pair, asc)

    // Update min and max sums with the smallest and largest pair sums
    min_sum += pair[0]
    max_sum += pair[idx-1]

    // Arrays for caching and counting
    cache := make([]int, z)
    cnt_map := make([]int, z)
    ans := make([]int64, RANK_MAX)

    // Calculate the size of the combined array
    size := x * y * z
    prev := min_sum
    r := 0

    // Iterate to find the rank-th largest sum
    for r = rank; r >= 1; r-- {
        low := prev - 1
        high := max_sum + 1

        // Binary search to find the appropriate sum
        for low+1 < high {
            mid := (low + high) / 2
            cnt := 0

            // Count how many sums are less than or equal to mid
            for i := 0; i < z; i++ {
                pivot := zrr[i]
                r.start = cache[i] - 1
                r.end = idx
                tmp := lower_bound(pair, r, mid-pivot)
                cnt_map[i] = tmp
                cnt += tmp
            }

            // Adjust the search range based on the count
            if cnt <= size-r {
                copy(cache, cnt_map)
                low = mid
            } else {
                high = mid
            }
        }

        // Store the found sum in the answer array
        ans[r-1] = low
        if low == max_sum {
            break // Stop if we reach the maximum sum
        }
        prev = low // Update previous sum for the next iteration
    }

    // Print the results for each rank
    for i := 0; i < rank; i++ {
        fmt.Printf("%d\n", (ans[i] == 0)? max_sum : ans[i])
    }
}

