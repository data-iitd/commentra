// Importing fmt and defining a custom input function
package main

import (
	"fmt"
	"os"
	"bufio"
	"strconv"
)

// Custom input function
func input() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

// Function to read an integer
func I() int {
	return int(input())
}

// Function to read multiple integers
func MI() []int {
	return []int(input())
}

// Function to read a list of integers
func LI() []int {
	return []int(input())
}

// Main function
func main() {
	// Setting the modulus value
	mod := 1000000007

	// Reading input values: N, A, and B
	N, A, B := MI()

	// Initializing the answer variable to 0
	ans := 0

	// Calculating the number of repetitions
	rep := N / (A + B)

	// Adding the number of blocks that can be fully covered by A and B in one repetition
	ans += rep * A

	// Calculating the remaining number of blocks
	res := N - rep * (A + B)

	// Adding the number of blocks that can be covered by A in the remaining blocks
	ans += min(res, A)

	// Printing the final answer
	fmt.Println(ans)
}

// Function to find the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// End of code
