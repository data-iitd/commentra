package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of elements
    n, _ := strconv.Atoi(os.Args[1])

    // Initialize a vector to store the input elements
    a := make([]int, n)

    // Read n integers into the vector
    for i := 0; i < n; i++ {
        a[i], _ = strconv.Atoi(os.Args[i+2])
    }

    // Initialize a counter for the current expected number
    curr := 0

    // Iterate through the vector to find the longest prefix of consecutive integers starting from 1
    for i := 0; i < n; i++ {
        if a[i] == curr+1 {
            curr++
        }
    }

    // Check if any consecutive integers were found
    if curr > 0 {
        // Print the number of elements not in the consecutive sequence
        fmt.Println(n - curr)
    } else {
        // If no consecutive integers were found, print -1
        fmt.Println(-1)
    }
}

