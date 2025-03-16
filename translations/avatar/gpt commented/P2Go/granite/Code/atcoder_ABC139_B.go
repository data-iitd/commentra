
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a new scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Read two integers from input and assign them to variables a and b
	scanner.Scan()
	line := scanner.Text()
	parts := strings.Split(line, " ")
	a, _ := strconv.Atoi(parts[0])
	b, _ := strconv.Atoi(parts[1])

	// Initialize the variable 'hole' to represent the current hole position
	hole := 1

	// Initialize a counter 'i' to track the number of iterations
	i := 0

	// Set a flag 'check' to control the while loop
	check := true

	// Continue looping until the condition is met
	for check {
		// Check if the current hole position is greater than or equal to b
		if hole >= b {
			// If so, exit the loop
			check = false
		} else {
			// Calculate the new hole position based on the formula
			hole = a * (i + 1) - i

			// Increment the iteration counter
			i++
		}
	}

	// Print the total number of iterations (i) when the loop ends
	fmt.Println(i)
}
