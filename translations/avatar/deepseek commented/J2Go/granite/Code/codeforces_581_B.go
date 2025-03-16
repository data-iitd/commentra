
package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Step 1: Open the input and output files
    reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    // Step 2: Read input values
    n, _ := strconv.Atoi(reader.ReadLine()[2 : len(reader.ReadLine())-1])
    a := make([]int64, n)
    for i := 0; i < n; i++ {
        a[i], _ = strconv.ParseInt(strings.TrimSpace(reader.ReadLine()), 10, 64)
    }

    // Step 3: Initialize a dynamic programming array
    dp := make([]int64, n+1)
    for i := n - 1; i >= 0; i-- {
        dp[i] = max(dp[i+1], a[i])
    }

    // Step 4: Calculate the result
    for i := 0; i < n; i++ {
        if a[i] > dp[i+1] {
            fmt.Fprint(writer, "0 ")
        } else {
            fmt.Fprint(writer, strconv.FormatInt(dp[i+1]-a[i]+1, 10)+" ")
        }
    }

    // Step 5: Print the result
    fmt.Fprintln(writer)
}

func max(a, b int64) int64 {
    if a > b {
        return a
    }
    return b
}

// Step 6: Debugging (optional)
func debug(args...interface{}) {
    fmt.Fprintln(os.Stderr, args...)
}

// Step 7: Close the input and output files
func check(e error) {
    if e!= nil {
        panic(e)
    }
}