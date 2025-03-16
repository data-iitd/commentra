
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line from standard input and strip any trailing whitespace characters.
func rs() string {
	s, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	return strings.TrimSpace(s)
}

// Function to read an integer from standard input.
func ri() int {
	i, _ := strconv.Atoi(rs())
	return i
}

// Function to read a list of strings from standard input.
func rs_() []string {
	return strings.Split(rs(), " ")
}

// Function to read a list of integers from standard input.
func ri_() []int {
	is := rs_()
	i := make([]int, len(is))
	for j := 0; j < len(is); j++ {
		i[j], _ = strconv.Atoi(is[j])
	}
	return i
}

func main() {
	// Read the integer value of N from standard input.
	N := ri()

	// Initialize the variable ans to 0.
	ans := 0

	// Start a loop that iterates from 1 to N + 1.
	for i := 1; i <= N; i++ {
		// Calculate the sum of multiples of i up to N using the formula for the sum of an arithmetic series.
		ans += i * (N / i) * (N/i + 1) / 2
	}

	// Print the final value of ans, which represents the sum of multiples of numbers from 1 to N.
	fmt.Println(ans)
}

