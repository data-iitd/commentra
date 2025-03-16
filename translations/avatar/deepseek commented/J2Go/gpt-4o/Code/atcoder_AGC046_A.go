package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Create a buffered reader to read input
	reader := bufio.NewReader(os.Stdin)

	// Read an integer input
	xStr, _ := reader.ReadString('\n')
	x, _ := strconv.Atoi(xStr[:len(xStr)-1]) // Convert string to integer

	// Initialize a counter to keep track of the number of iterations
	count := 0
	// Store the initial value of x in a temporary variable
	tmp := x

	// Initialize x to 0 to start the loop
	x = 0

	// Loop until x becomes 360
	for x != 360 {
		// Increment x by tmp
		x += tmp
		// If x exceeds 360, adjust it by subtracting 360
		if x > 360 {
			x -= 360
		}
		// Increment the counter
		count++
	}

	// Print the final count
	fmt.Println(count)
}

// <END-OF-CODE>
