package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	// Create a new Scanner to read input from the user
	scanner := bufio.NewScanner(os.Stdin)

	// Read an integer value n from the user and store it in the variable n
	var n int
	fmt.Print("Enter an integer value n: ")
	scanner.Scan()
	n, _ = strconv.Atoi(scanner.Text())

	// Loop n times to read pairs of integers and print their greatest common divisor
	for i := 0; i < n; i++ {
		// Read two integers a and b from the user and store them in the variables a and b
		var a, b int
		fmt.Print("Enter two integers a and b: ")
		scanner.Scan()
		input := strings.Split(scanner.Text(), " ")
		a, _ = strconv.Atoi(input[0])
		b, _ = strconv.Atoi(input[1])

		// Call the sub method with the values of a and b as arguments and print the result
		fmt.Println(sub(a, b))
	}
}

// Define the sub method to calculate the greatest common divisor using the Euclidean algorithm
func sub(a, b int) int {
	// Initialize min and max to store the smaller and larger of the two input values
	min := a
	if b < a {
		min = b
	}
	max := a
	if b > a {
		max = b
	}

	// Initialize result to 0, which will be used to store the result of the Euclidean algorithm
	result := 0

	// Apply the Euclidean algorithm until min becomes 0
	for min > 0 {
		// Add the quotient of max divided by min to result
		result += max / min

		// Update max to be the remainder of max divided by min
		max = max % min

		// Swap min and max if necessary to ensure min is the smaller value
		if min > max {
			min, max = max, min
		}
	}

	// Return the value of result, which represents the greatest common divisor
	return result
}

