package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Declare variables
    var n, x, min, m, i int

    // Read the number of elements (n), a value (x), and the initial minimum value (min)
    n, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))
    x, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))
    min, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))

    // Adjust x by subtracting the initial minimum value
    x -= min

    // Loop through the remaining n-1 elements to read their values
    for i = 1; i < n; i++ {
        // Read the next element into variable m
        m, _ = strconv.Atoi(strings.TrimSpace(string(os.Stdin.Read(make([]byte, 1000000)))))

        // Subtract the current element from x
        x -= m

        // Update min if the current element is smaller than the current minimum
        if min > m {
            min = m
        }
    }

    // Calculate and print the result based on the number of elements and the adjusted x divided by the minimum value
    fmt.Printf("%d\n", n+x/min)
}

