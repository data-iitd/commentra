// ABC 152-D
// 2020.1.19 bal4u

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

// Fast input function to read a character from standard input
func gc() rune {
    var c rune
    fmt.Scanf("%c", &c)
    return c
}

// Function to read a non-negative integer from input
func in() int {   // 非負整数の入力
    var n int
    var c rune
    fmt.Scanf("%c", &c)
    for c >= '0' {
        n = n*10 + int(c-'0')
        fmt.Scanf("%c", &c)
    }
    return n
}

// Arrays to store frequency counts for two different calculations
var f1 [100]int
var f2 [100]int

// Function to calculate frequency counts based on the input number
func calc(n int) {
    k := n % 10 // Extract the last digit of n
    // Reduce n to its first digit by continuously dividing by 10
    for n >= 10 {
        n /= 10
    }
    // Update frequency counts for combinations of first and last digits
    f1[10*k + n]++
    f2[n*10 + k]++
}

func main() {
    var i, N, ans int // Declare variables for iteration, input number, and answer
    
    // Read the total number of inputs
    N = in()
    // Process each number from N down to 1
    for ; N > 0; N-- {
        calc(N)
    }

    ans = 0 // Initialize answer to 0
    // Calculate the final answer by summing the products of corresponding frequencies
    for i = 0; i < 100; i++ {
        ans += f1[i] * f2[i]
    }
    // Output the final answer
    fmt.Printf("%d\n", ans)
}

