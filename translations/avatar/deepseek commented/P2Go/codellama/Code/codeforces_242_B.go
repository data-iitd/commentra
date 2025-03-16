
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements
    var n int
    fmt.Scan(&n)

    // Initialize variables to track the best candidate interval
    id := 0
    l, r := readInts(2)

    // Process each interval
    for i := 1; i < n; i++ {
        li, ri := readInts(2)
        // Check if the current interval completely covers the best candidate interval
        if li <= l && r <= ri {
            id = i
        }
        // Check if the current interval overlaps with the best candidate interval
        if li < l || r < ri {
            id = n
        }
        // Update the boundaries of the best candidate interval
        l = min(l, li)
        r = max(r, ri)
    }

    // Output the result
    if id == n {
        fmt.Println(-1)
    } else {
        fmt.Println(id + 1)
    }
}

func readInts(n int) (int, int) {
    var li, ri int
    fmt.Scan(&li, &ri)
    return li, ri
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// 