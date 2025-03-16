package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

// Function to read a line from standard input and remove trailing whitespace
func rs() string {
	reader := bufio.NewReader(os.Stdin)
	line, _ := reader.ReadString('\n')
	return line[:len(line)-1]
}

// Function to read an integer from standard input
func ri() int {
	num, _ := strconv.Atoi(rs())
	return num
}

// Function to read a line from standard input and return a list of strings
func rs_() []string {
	line := rs()
	return strings.Split(line, " ")
}

// Function to read a line from standard input and return a list of integers
func ri_() []int {
	parts := rs_()
	ints := make([]int, len(parts))
	for i, part := range parts {
		ints[i], _ = strconv.Atoi(part)
	}
	return ints
}

func main() {
	// Read the integer N from input
	N := ri()

	// Initialize the answer variable to accumulate the result
	ans := 0

	// Loop through each integer from 1 to N (inclusive)
	for i := 1; i <= N; i++ {
		// Calculate the contribution of the current integer i to the answer
		quotient := N / i
		ans += i * quotient * (quotient + 1) / 2
	}

	// Print the final result
	fmt.Println(ans)
}
