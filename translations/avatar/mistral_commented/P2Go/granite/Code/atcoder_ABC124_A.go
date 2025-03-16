
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Prompt the user to enter two integers separated by a space
	fmt.Print("Enter two integers separated by a space: ")
	scanner.Scan()

	// Split the input string into two integers
	input := scanner.Text()
	a, b := strconv.Atoi(input[0:len(input)/2]), strconv.Atoi(input[len(input)/2+1:len(input)])

	// Initialize a variable 'c' to store the sum of the larger numbers in each iteration
	c := 0

	// Loop through the given condition for 2 times
	for i := 0; i < 2; i++ {

		// Calculate the sum of the larger number in each iteration and add it to the variable 'c'
		c += max(a, b)

		// Update the smaller number in each iteration
		if a >= b {
			a--
		} else {
			b--
		}
	}

	// Print the final result
	fmt.Println(c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

