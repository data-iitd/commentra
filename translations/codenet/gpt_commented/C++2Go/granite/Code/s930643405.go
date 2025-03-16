
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize the input reader
	reader := bufio.NewReader(os.Stdin)

	// Read the initial number 'n' and the count of forbidden digits 'k'
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	// Initialize an array to track forbidden digits
	d := make([]bool, 10) // Initialize all digits as not forbidden

	// Read the forbidden digits and mark them in the array
	for i := 0; i < k; i++ {
		var a int
		fmt.Fscanf(reader, "%d\n", &a) // Input each forbidden digit
		d[a] = true // Mark the digit as forbidden
	}

	// Infinite loop to find the next valid number
	for {
		x := n // Start checking from the current number 'n'
		hantei := true // Reset the validity flag for the new number

		// Check each digit of the number 'x'
		for x > 0 {
			// If the current digit is forbidden
			if d[x%10] {
				hantei = false // Mark the number as invalid
				break // Exit the digit checking loop
			}
			x /= 10 // Remove the last digit
		}

		// If the number is valid (no forbidden digits found)
		if hantei {
			fmt.Println(n) // Output the valid number
			break // Exit the infinite loop
		}
		n++ // Increment the number and check the next one
	}
}

