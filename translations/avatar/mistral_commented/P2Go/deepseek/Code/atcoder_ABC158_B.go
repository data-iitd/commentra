package main

import (
	"bufio"
	"fmt"
	"os"
)

var sc = bufio.NewScanner(os.Stdin)

// Custom input function
func input() string {
	sc.Scan()
	return sc.Text()
}

// Function to read an integer
func I() int {
	return toInt(input())
}

// Function to read multiple integers
func MI() (int, int) {
	sc.Scan()
	values := split(sc.Text(), " ")
	return toInt(values[0]), toInt(values[1])
}

// Function to read a list of integers
func LI() []int {
	sc.Scan()
	values := split(sc.Text(), " ")
	intValues := make([]int, len(values))
	for i, v := range values {
		intValues[i] = toInt(v)
	}
	return intValues
}

// Helper function to convert string to int
func toInt(s string) int {
	var result int
	fmt.Sscanf(s, "%d", &result)
	return result
}

// Helper function to split string by delimiter
func split(s, delim string) []string {
	result := make([]string, 0)
	for _, v := range s {
		if string(v) == delim {
			continue
		}
		result = append(result, string(v))
	}
	return result
}

// Main function
func main() {
	// Setting the modulus value
	const mod = 1000000007

	// Reading input values: N, A, and B
	N, A, B := MI()

	// Initializing the answer variable to 0
	ans := 0

	// Calculating the number of repetitions
	rep := N / (A + B)

	// Adding the number of blocks that can be fully covered by A and B in one repetition
	ans += rep * A

	// Calculating the remaining number of blocks
	res := N - rep*(A+B)

	// Adding the number of blocks that can be covered by A in the remaining blocks
	ans += min(res, A)

	// Printing the final answer
	fmt.Println(ans)
}

// Helper function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

