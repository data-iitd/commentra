package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Declare an array to hold the input values
var a [100100]int

func main() {
    var k int
    fmt.Scanf("%d", &k)

    // Read the input values into the array
    for i := 0; i < k; i++ {
        fmt.Scanf("%d", &a[i])
    }

    var min, max int
    max = 3
    min = 2

    // Check if the last element is not equal to 2
    if a[k-1]!= 2 {
        fmt.Println(-1)
        return
    }

    // Iterate through the array from the second last element to the first
    for i := k - 2; i >= 0; i-- {
        // If the current element is greater than max, output -1
        if a[i] > max {
            fmt.Println(-1)
            return
        } else {
            // Update max based on the current element
            max = ((max / a[i]) + 1) * a[i] - 1
            // Adjust min to be a multiple of the current element if necessary
            if min%a[i]!= 0 {
                min = ((min / a[i]) + 1) * a[i]
            }
        }

        // Check if the updated max is less than or equal to min
        if max <= min {
            fmt.Println(-1)
            return
        }
    }

    // Output the final min and max values
    fmt.Printf("%d %d\n", min, max)
}

