
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Declare variables to hold two integers and intermediate results
	var a, b, x, w int

	// Create a scanner to read input from the standard input
	scanner := bufio.NewScanner(os.Stdin)

	// Continuously read pairs of integers until the scanner encounters an error
	for scanner.Scan() {
		// Split the input string into two integers
		fields := strings.Fields(scanner.Text())
		a, _ = strconv.Atoi(fields[0])
		b, _ = strconv.Atoi(fields[1])

		// Calculate the sum of the two integers
		x = a + b

		// Initialize a counter for the number of digits in the sum
		w = 0

		// Count the number of digits in the sum (x)
		for x > 0 {
			// Increment the digit counter
			w++
			// Remove the last digit from x by dividing by 10
			x /= 10
		}

		// Print the number of digits in the sum
		fmt.Println(w)
	}

	// Check for any errors during input reading
	if err := scanner.Err(); err!= nil {
		fmt.Println("Error reading input:", err)
	}
}

