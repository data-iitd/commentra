package main

import (
	"fmt"
	"math"
	"os"
	"strconv"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	// Read two integers from input
	var a, b int
	fmt.Fscan(in, &a, &b)
	c := 0 // Initialize counter for the number of operations

	// Check for the special case where both a and b are 1
	if a == 1 && b == 1 {
		fmt.Fprintln(out, 0) // Output 0 operations needed
	} else {
		// Loop until both a and b are non-positive
		for a >= 1 || b >= 1 {
			// If a is greater than or equal to b, perform operation on a
			if a >= b {
				b++ // Increment b
				a -= 2 // Decrement a by 2
			} else {
				// If b is greater than a, perform operation on b
				a++ // Increment a
				b -= 2 // Decrement b by 2
			}

			// Check if either a or b has become non-positive
			if a <= 0 || b <= 0 {
				c++ // Increment operation counter and break
				break
			}
			c++ // Increment operation counter
		}
		// Output the total number of operations performed
		fmt.Fprintln(out, c)
	}
}

// Swap method (not used in this code)
func swap(a, b int) {
	t := b
	b = a
	a = t
}

// Debug method for printing objects (not used in this code)
func debug(obj ...interface{}) {
	fmt.Fprintln(os.Stderr, obj...)
}

