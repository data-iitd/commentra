package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to read a single line from standard input and strip any trailing whitespace characters.
func rs() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

// Function to read an integer from standard input.
func ri() int {
	num, _ := strconv.Atoi(rs())
	return num
}

// Function to read a list of strings from standard input.
func rs_() []string {
	line := rs()
	return strings.Split(line, " ")
}

// Function to read a list of integers from standard input.
func ri_() []int {
	lines := rs_()
	ints := make([]int, len(lines))
	for i, line := range lines {
		ints[i], _ = strconv.Atoi(line)
	}
	return ints
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

