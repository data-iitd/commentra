package main

import (
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object to read input from the console
	in := bufio.NewScanner(os.Stdin)

	// Read three integers from the input: T, S, and q
	var T, S, q int
	fmt.Scan(&T, &S, &q)

	previous := S // Initialize 'previous' with the starting value S
	answer := 0    // Initialize the answer counter

	// Loop until 'previous' is less than 'T'
	for previous < T {
		answer++ // Increment the answer counter
		previous *= q // Multiply 'previous' by 'q' for the next iteration
	}

	// Output the final count of how many times 'previous' was multiplied before reaching 'T'
	fmt.Println(answer)
}

