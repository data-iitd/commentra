package main

import (
    "bufio"
    "fmt"
    "os"
    "sort"
    "strconv"
    "strings"
)

// Global variables
var n, k int
var vec []int
var ans int = 1000000001

func main() {
    // Read the number of elements (n) and the size of the subset (k)
    fmt.Scanf("%d %d\n", &n, &k)

    // Read n integers from input and store them in the vector
    for i := 0; i < n; i++ {
        var t int
        fmt.Scanf("%d\n", &t)
        vec = append(vec, t)
    }

    // Sort the vector in non-decreasing order
    sort.Ints(vec)

    // Iterate through the sorted vector to find the minimum difference
    for i := 0; i+k-1 < n; i++ {
        // Calculate the difference between the maximum and minimum of the current subset of size k
        diff := vec[i+k-1] - vec[i]

        // Update the minimum difference found so far
        if diff < ans {
            ans = diff
        }
    }

    // Output the minimum difference found
    fmt.Println(ans)
}

