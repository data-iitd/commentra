package main

import (
    "fmt"
    "math"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Declare arrays to store input values, prefix sums, and suffix sums
var a []int64
var pre []int64
var last []int64

func main() {
    var n int
    // Read the number of elements
    fmt.Scanf("%d", &n)
    
    // Read the input values into the array 'a'
    for i := 0; i < n; i++ {
        var x int64
        fmt.Scanf("%d", &x)
        a = append(a, x)
    }

    var sumpre, sumlast int64

    // Calculate prefix sums and store them in 'pre' array
    for i := 0; i < n - 1; i++ {
        sumpre = sumpre + a[i]
        pre = append(pre, sumpre)
        // Debugging output for prefix sums (commented out)
        // fmt.Printf("%d++\n", pre[i])
    }

    // Calculate suffix sums and store them in 'last' array
    for i := n - 1; i > 0; i-- {
        sumlast = sumlast + a[i]
        last = append(last, sumlast)
        // Debugging output for suffix sums (commented out)
        // fmt.Printf("%d+++\n", last[i])
    }

    // Initialize 'd' to a large value to find the minimum difference
    var d int64 = math.MaxInt64

    // Calculate the minimum absolute difference between prefix and suffix sums
    for i := 0; i < n - 1; i++ {
        // Debugging output for the difference calculation (commented out)
        // fmt.Printf("%d\n", pre[i] - last[i + 1])
        d = int64(math.Min(d, math.Abs(float64(pre[i] - last[i + 1]))))
    }

    // Output the minimum difference found
    fmt.Printf("%d\n", d)
}

