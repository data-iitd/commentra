package main

import (
	"fmt"
)

func main() {
	// Loop to process 4 test cases
	for i := 0; i < 4; i++ {
		var t, n int
		// Read the type (t) and quantity (n) from input
		fmt.Scan(&t, &n)

		// Calculate and output the result based on the type (t)
		switch t {
		case 1:
			// If type is 1, multiply n by 6000
			fmt.Println(6000 * n)
		case 2:
			// If type is 2, multiply n by 4000
			fmt.Println(4000 * n)
		case 3:
			// If type is 3, multiply n by 3000
			fmt.Println(3000 * n)
		case 4:
			// If type is 4, multiply n by 2000
			fmt.Println(2000 * n)
		}
	}
}

// <END-OF-CODE>
