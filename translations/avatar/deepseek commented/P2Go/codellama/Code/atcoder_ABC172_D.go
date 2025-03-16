
package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line from standard input and strip any trailing whitespace characters.
func rs() string {
	return strings.TrimRight(readLine(), "\r\n")
}

// Function to read an integer from standard input.
func ri() int {
	return int(readInt())
}

// Function to read a list of strings from standard input.
func rs_() []string {
	return strings.Split(rs(), " ")
}

// Function to read a list of integers from standard input.
func ri_() []int {
	return []int{readInt(), readInt()}
}

// Function to read an integer from standard input.
func readInt() int {
	i, _ := strconv.Atoi(rs())
	return i
}

// Function to read a single line from standard input.
func readLine() string {
	var line string
	if _, err := fmt.Scan(&line); err != nil {
		fmt.Println(err)
	}
	return line
}

// Read the integer value of N from standard input.
N := ri()

// Initialize the variable ans to 0.
ans := 0

// Start a loop that iterates from 1 to N + 1.
for i := 1; i <= N+1; i++ {
	// Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
	ans += i * (N / i) * (N / i + 1) / 2
}

// Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
fmt.Println(ans)

// End of code.
