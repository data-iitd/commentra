package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n int
    var a [100000]int
    var cnt int = 1
    var isup bool
    var issame bool = false

    // Read the number of elements
    fmt.Scanf("%d", &n)

    // Read the elements into the array
    for i := 0; i < n; i++ {
        fmt.Scanf("%d", &a[i])
    }

    // Determine the initial trend based on the first two elements
    if a[0] < a[1] {
        isup = true
    } else if a[0] > a[1] {
        isup = false
    } else {
        issame = true
    }

    // Iterate through the array to count segments
    for i := 1; i < n - 1; i++ {
        // Handle the case where previous elements are the same
        if issame {
            if a[i]!= a[i + 1] {
                issame = false
                if a[i] < a[i + 1] {
                    isup = true
                } else {
                    isup = false
                }
            }
        } else {
            // Check if the current trend is maintained
            if isup && a[i] <= a[i + 1] {
                // Trend is increasing and maintained
                ;
            } else if!isup && a[i] >= a[i + 1] {
                // Trend is decreasing and maintained
                ;
            } else {
                // Trend has changed
                if i + 2 < n {
                    // Determine the new trend based on the next element
                    if a[i + 1] < a[i + 2] {
                        isup = true
                    } else if a[i + 1] > a[i + 2] {
                        isup = false
                    } else {
                        issame = true
                    }
                    cnt++
                } else {
                    cnt++
                    break
                }
            }
        }
    }

    // Output the total number of segments
    fmt.Printf("%d\n", cnt)
}

