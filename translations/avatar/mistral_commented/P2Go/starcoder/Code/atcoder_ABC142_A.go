package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func main() {
    // Read an integer `n` from the user
    n, _ := strconv.Atoi(readLine())
    // Initialize a variable `t` to zero
    t := 0
    // Iterate through the range of integers from 0 to n-1
    for i := 0; i < n; i++ {
        // Check if the index i is odd
        if i+1&1 == 1 {
            // If it is odd, increment the variable t by 1
            t += 1
    }
    // Print the result t/n as the output
    fmt.Printf("%.6f\n", float64(t)/float64(n))
}

func readLine() string {
    buf := bufio.NewReader(os.Stdin)
    str, _, _ := buf.ReadLine()
    return strings.TrimRight(string(str), "\r\n")
}

