package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

func main() {
	// Initialize input reader
	reader := bufio.NewReader(os.Stdin)

	// Read input line
	input, _ := reader.ReadString('\n')
	// Split the input into tokens
	tokens := strings.Fields(input)

	// Parse integers a, b, c, and d
	a, _ := strconv.Atoi(tokens[0])
	b, _ := strconv.Atoi(tokens[1])
	c, _ := strconv.Atoi(tokens[2])
	d, _ := strconv.Atoi(tokens[3])

	// Check if c is greater than b
	if c > b {
		// If yes, print 0 and exit
		fmt.Println(0)
		return
	}

	// Check if a is greater than d
	if a > d {
		// If yes, print 0 and exit
		fmt.Println(0)
		return
	}

	// Check if a is less than c
	if a < c {
		// If yes, calculate the difference between the smaller and larger of b and d
		difference := min(b, d) - c
		// Print the difference
		fmt.Println(difference)
		return
	}

	// If none of the above conditions are true, then a, b, c, and d are in sorted order
	// Create a slice of integers a, b, c, and d
	numbers := []int{a, b, c, d}

	// Sort the slice in ascending order
	sort.Ints(numbers)

	// Calculate the difference between the second and third elements of the slice
	difference := numbers[2] - numbers[1]

	// Print the difference
	fmt.Println(difference)
}

// Helper function to find the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
