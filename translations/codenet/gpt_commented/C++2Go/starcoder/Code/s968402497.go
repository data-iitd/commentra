package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read the number of test cases, and two integers n and m
    tc, n, m := 0, 0, 0
    fmt.Scanf("%d%d%d", &tc, &n, &m)

    // Ensure n is the smaller of the two integers
    if n > m {
        n, m = m, n
    }

    // Loop through the range from 1 to m
    for i := 1; i <= m; i++ {
        // Check if the current value multiplied by tc is within the range [n, m]
        if i*tc >= n && i*tc <= m {
            fmt.Println("OK") // Print "OK" if the condition is satisfied
            break // Exit the loop as we found a valid case
        }
    }

    // If no valid case was found, print "NG"
    if i > m {
        fmt.Println("NG")
    }
}

