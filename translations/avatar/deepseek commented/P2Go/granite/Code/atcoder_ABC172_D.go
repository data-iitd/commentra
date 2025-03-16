

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

// Function to read a single line from standard input and strip any trailing whitespace characters.
func rs() string {
    s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
    return s[:len(s)-1]
}

// Function to read an integer from standard input.
func ri() int {
    s := rs()
    i, _ := strconv.Atoi(s)
    return i
}

// Function to read a list of strings from standard input.
func rs_() []string {
    s := rs()
    return strings.Split(s, " ")
}

// Function to read a list of integers from standard input.
func ri_() []int {
    s := rs_()
    i := make([]int, len(s))
    for j, v := range s {
        i[j], _ = strconv.Atoi(v)
    }
    return i
}

// Read the integer value of N from standard input.
func main() {
    N := ri()

    // Initialize the variable ans to 0.
    ans := 0

    // Start a loop that iterates from 1 to N + 1.
    for i := 1; i <= N; i++ {
        // Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
        ans += i * (N / i) * (N / i + 1) / 2
    }

    // Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
    fmt.Println(ans)
}

