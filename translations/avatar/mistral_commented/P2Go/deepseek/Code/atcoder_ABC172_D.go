package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

// Function to read a single line from standard input and return it as a string
// with the trailing newline character removed
func rs() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return strings.TrimRight(line, "\n")
}

// Function to read a single integer from standard input
func ri() int {
	line := rs()
	num, _ := strconv.Atoi(line)
	return num
}

// Function to read a list of integers from standard input
// Each line of input is assumed to contain space-separated integers
func ri_() []int {
	line := rs()
	parts := strings.Split(line, " ")
	nums := make([]int, len(parts))
	for i, part := range parts {
		num, _ := strconv.Atoi(part)
		nums[i] = num
	}
	return nums
}

func main() {
	// Read the number of test cases from standard input
	N := ri()

	// Initialize the answer to 0
	ans := 0

	// Iterate through all numbers from 1 to N
	for i := 1; i <= N; i++ {
		// Calculate the contribution of i to the answer
		// The formula is given by the problem statement
		quotient := N / i
		ans += i * quotient * (quotient + 1) / 2
	}

	// Print the answer
	fmt.Println(ans)
}

