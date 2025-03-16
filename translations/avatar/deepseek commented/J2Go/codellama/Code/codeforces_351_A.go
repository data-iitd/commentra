
package main

import (
    "bufio"
    "fmt"
    "io"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Reading Input
    var n int
    fmt.Scan(&n)
    var arr []float64 = make([]float64, 2*n)
    var non_int int = 0
    var sum_before float64 = 0
    var sum float64 = 0

    // Step 2: Processing Input
    for i := 0; i < 2*n; i++ {
        var num float64
        fmt.Scan(&num)
        sum_before += num
        if num != float64(int(num)) {
            non_int++
        }
        sum += float64(int(num))
        arr[i] = num
    }

    // Step 3: Calculating Results
    var max_sum float64 = float64(math.Min(float64(n), float64(non_int))) + sum
    var min_sum float64 = float64(math.Max(float64(0), float64(non_int-n))) + sum
    var ans float64

    if min_sum > sum_before {
        ans = min_sum - sum_before
    } else if max_sum < sum_before {
        ans = sum_before - max_sum
    } else {
        var x float64 = sum_before - float64(int(sum_before))
        ans = float64(math.Min(float64(1)-x, x))
    }

    // Step 4: Output
    fmt.Printf("%.3f", ans)
}

