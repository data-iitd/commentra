<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Declare variables
	var i_min, min int
	var i, j, k int

	// Read input values X and N from the user
	X, N := readInput()

	// Check if N is zero, if yes, print X and exit the program
	if N == 0 {
		fmt.Println(X)
		os.Exit(0)
	}

	// Initialize two arrays plus and minus of size 256
	plus := make([]int, 256)
	minus := make([]int, 256)
	for i = 0; i < 256; i++ {
		// Initialize plus array with numbers from 0 to 255
		plus[i] = i
		// Initialize minus array with negative numbers of plus array
		minus[i] = -1 * i
	}

	// Subtract the given numbers from the plus array
	for i = 0; i < N; i++ {
		j = readInput()
		// Set the corresponding index in the plus array to zero
		plus[j] = 0
	}

	// Initialize variables i_min and min with initial values
	i_min = 0
	min = 1000

	// Find the minimum number in the plus array that is not zero and can form the difference X
	for i = 255; i >= 0; i-- {
		// Skip the iteration if the current number in the plus array is zero and it is not the first element
		if plus[i] == 0 && i > 0 {
			continue
		}
		// Calculate the difference between X and the current number in the plus array
		k = X - plus[i]
		// If the difference is negative, make it positive
		if k < 0 {
			k *= -1
		}
		// Update min and i_min if the current difference is smaller than the previous minimum
		if k <= min {
			min = k
			i_min = i
		}
	}

	// Print the index of the minimum number
	fmt.Println(i_min)
}

// readInput reads input from stdin
func readInput() (int, int) {
	// Read input from stdin
	input, _ := os.Stdin.ReadString('\n')
	// Remove the trailing newline character
	input = strings.TrimSuffix(input, "\n")
	// Split the input into two strings
	input = strings.Split(input, " ")
<<<<<<< HEAD
	// Convert the strings to integers
	X, _ := strconv.Atoi(input[0])
	N, _ := strconv.Atoi(input[1])
	// Return the integers
=======
	// Convert the two strings into integers
	X, _ := strconv.Atoi(input[0])
	N, _ := strconv.Atoi(input[1])
	// Return the two integers
>>>>>>> 98c87cb78a (data updated)
	return X, N
}

