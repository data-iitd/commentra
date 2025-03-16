package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var i, n int
    var tmp, min, max, sum int64

    // Read the number of integers to be processed
    n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.ReadByte())))

    // Loop to read n integers
    for i = 0; i < n; i++ {
        // Read the next integer
        tmp, _ = strconv.ParseInt(strings.TrimSpace(string(os.Stdin.ReadByte())), 10, 64)

        // Update min if the current number is smaller
        if min > tmp {
            min = tmp
        }

        // Update max if the current number is larger
        if max < tmp {
            max = tmp
        }

        // Add the current number to the sum
        sum += tmp
    }

    // Print the minimum, maximum, and sum of the numbers
    fmt.Printf("%d %d %d\n", min, max, sum)
}

