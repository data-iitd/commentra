package main

import (
	"fmt"
)

func main() {
	var a int // Declare variable to store input

	// Start a loop to read input
	for {
		_, err := fmt.Scan(&a) // Read an integer 'a' from the input
		if err != nil {        // Check for input error
			break              // Exit the loop if there's an error
		}

		if a < 3 { // Check if 'a' is less than 3
			fmt.Println(0) // Print 0 if 'a' is less than 3
		} else {
			c, k := 0, 0 // Initialize counters 'c' and 'k' to 0
			b := a       // Store the initial value of 'a' in 'b' for later use

			for a > 0 { // Loop while 'a' is greater than 0
				b-- // Decrement 'b' in each iteration
				c++ // Increment 'c' in each iteration
				if c == 3 { // Check if 'c' equals 3
					k++ // Increment 'k'
					c = 0 // Reset 'c' to 0
				}
				a-- // Decrement 'a'
			}
			fmt.Println(k) // Print the number of times 'c' reset to 0
		}
	}
}

// <END-OF-CODE>
