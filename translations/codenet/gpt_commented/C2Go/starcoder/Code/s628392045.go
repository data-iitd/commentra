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
    var i int
    var h [100001]int
    var max int
    var flag int

    // Read the number of elements
    fmt.Scanf("%d", &n)

    // Loop to read heights and determine the maximum height
    for i = 0; i < n; i++ {
        // Read height into the array
        fmt.Scanf("%d", &h[i])

        // Update maximum height if current height is greater
        if max < h[i] {
            max = h[i]
        }

        // Check if the difference between max height and current height is 2 or more
        if max-h[i] >= 2 {
            flag = 1
        }
    }

    // Output result based on the flag value
    if flag == 1 {
        fmt.Println("No")
    } else {
        fmt.Println("Yes")
    }
}

