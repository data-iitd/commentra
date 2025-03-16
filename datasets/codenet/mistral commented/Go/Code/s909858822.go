// Import the "fmt" package for formatted I/O
package main

import (
	"fmt"
)

func main() {
	// Declare two integer variables, A and B, and read their values from the standard input
	var A, B int
	fmt.Scanln(&A, &B)

	// Declare an integer variable, ans, to store the result of our calculation
	var ans int

	// Use an if statement to check the value of A
	if A >= 6 && A <= 12 {
		// If A is between 6 and 12 (inclusive), calculate the answer as the integer division of B by 2
		ans = B / 2
	} else if A > 12 {
		// If A is greater than 12, assign the value of B directly to the ans variable
		ans = B
	}

	// Print the value of ans
	fmt.Println(ans)

	// End of code
}