
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	// Initialize some variables
	d := make([]bool, 10) // A boolean array to keep track of digits that have been seen
	n := 0 // Input variable for the number
	k := 0 // Input variable for the number of digits to check
	hantei := true // A flag to indicate if the current number is a valid answer

	// Read input
	reader := bufio.NewReader(os.Stdin)
	fmt.Fscanf(reader, "%d %d\n", &n, &k)

	// Check each digit in the input number 'k' times
	for i := 0; i < k; i++ {
		a := 0 // A variable to store the digit to check
		fmt.Fscanf(reader, "%d", &a) // Read the digit from the input
		d[a] = true // Mark the digit as seen
	}

	// Keep generating numbers until a valid one is found
	for {
		x := n // Initialize a variable 'x' to store the current number being checked

		// Initialize a flag 'hantei' to indicate if the current number is valid
		hantei = true

		// Check each digit in the number 'x'
		for x > 0 {
			// If the current digit has already been seen, then the number is not valid
			if d[x%10] {
				hantei = false
				break
			}
			x /= 10 // Move to the next digit
		}

		// If the current number is valid, print it and exit the loop
		if hantei {
			fmt.Println(n)
			break
		}

		// If the current number is not valid, increment 'n' and continue checking
		n++
	}
}

