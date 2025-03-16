package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	// Create a Scanner object for input and a PrintWriter for output
	in := bufio.NewScanner(os.Stdin)
	in.Split(bufio.ScanWords)
	pw := bufio.NewWriter(os.Stdout)
	defer pw.Flush()
	
	// Read two integers from input
	in.Scan()
	a := parseInt(in.Text())
	in.Scan()
	b := parseInt(in.Text())
	c := 0 // Initialize counter for the number of operations
	
	// Check for the special case where both a and b are 1
	if a == 1 && b == 1 {
		fmt.Fprintln(pw, 0) // Output 0 operations needed
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
		fmt.Fprintln(pw, c)
	}
}

// Helper function to parse string to int
func parseInt(s string) int {
	var res int
	for i := 0; i < len(s); i++ {
		res = res*10 + int(s[i]-'0')
	}
	return res
}
