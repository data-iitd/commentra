package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanln(&s) // Taking input string s
	var n int
	fmt.Scanln(&n) // Taking integer input n
	ans := 0       // Initializing the answer variable to 0

	// Loop runs n times
	for i := 0; i < n; i++ {
		var x string
		fmt.Scanln(&x) // Taking input for string x of length 2
		a, b := 0, 0   // Initializing counters a and b to 0

		// Iterating over each character in the string s
		for _, j := range s {
			if j == rune(x[0]) { // Checking if the character matches the first character of x
				a++ // Incrementing the count for the first character
			} else if j == rune(x[1]) { // Checking if the character matches the second character of x
				b++ // Incrementing the count for the second character
			} else { // If the character does not match any of the two
				ans += min(a, b) // Adding the minimum of a and b to ans
				a, b = 0, 0      // Resetting the counters a and b to 0
			}
		}

		ans += min(a, b) // Adding the minimum of a and b to ans after the inner loop
	}

	fmt.Println(ans) // Printing the final answer
}

// Helper function to find the minimum of two integers
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// <END-OF-CODE>
