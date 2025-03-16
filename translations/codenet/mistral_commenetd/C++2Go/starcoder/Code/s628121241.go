
<<<<<<< HEAD
=======
package main
>>>>>>> 98c87cb78a (data updated)

import (
	"fmt"
	"math"
)

// Function to find the greatest common divisor (GCD) of two numbers
func gcd(a, b int) int {
	// Base case: if 'a' is 0, return 'b' as the GCD
	if a == 0 {
		return b
	}
	// Recursive case: call the function with the remainder of 'a' and 'b' as arguments
	return gcd(b%a, a)
}

func main() {
	// Declare and read the value of 'R' from the standard input
	var R int
	fmt.Scanln(&R)

	// Check the value of 'R' and print the corresponding output
	if R < 1200 {
		fmt.Println("ABC") // Output: "ABC" if 'R' is less than 1200
	} else if R >= 2800 {
		fmt.Println("AGC") // Output: "AGC" if 'R' is greater than or equal to 2800
	} else {
		fmt.Println("ARC") // Output: "ARC" if 'R' is between 1200 and 2800 (inclusive)
	}
}

