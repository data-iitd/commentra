package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Set the recursion limit to avoid infinite recursion
	// This is not applicable in Go, as Go handles recursion differently

	// Debugging function to print debug information if TERM_PROGRAM is in os.Environ()
	// This is not applicable in Go, as Go does not have a direct equivalent for environ

	// Function to read input from stdin without trailing whitespace
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	input := scanner.Text()

	// Helper function to read a list of integers
	LMIIS := func() []int {
		parts := strings.Split(input, " ")
		intParts := make([]int, len(parts))
		for i, part := range parts {
			intPart, _ := strconv.Atoi(part)
			intParts[i] = intPart
		}
		return intParts
	}

	// Helper function to read a single integer
	II := func() int {
		scanner.Scan()
		input := scanner.Text()
		num, _ := strconv.Atoi(input)
		return num
	}

	// Constant for modulo operation
	const P = 1000000007

	// Constant for infinity
	const INF = 100000000010

	// Read two inputs, convert one to integer and the other to scaled integer
	parts := strings.Split(input, " ")
	a, _ := strconv.Atoi(parts[0])
	bFloat, _ := strconv.ParseFloat(parts[1], 64)
	bScaled := int(bFloat * 100.0)

	// Perform the calculation and print the result
	result := a * bScaled / 100
	fmt.Println(result)
}

