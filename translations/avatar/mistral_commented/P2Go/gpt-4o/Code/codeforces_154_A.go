package main

import (
	"fmt"
)

func main() {
	// Take the input string 's' and an integer 'n' from the user
	var s string
	fmt.Scanln(&s)

	var n int
	fmt.Scanln(&n)

	// Initialize the answer variable 'ans' to 0
	ans := 0

	// Iterate through the given range 'n' times
	for i := 0; i < n; i++ {
		// Take the next string 'x' as input
		var x string
		fmt.Scanln(&x)

		// Initialize variables 'a' and 'b' to 0
		a, b := 0, 0

		// Iterate through each character 'j' in the string 's'
		for _, j := range s {
			// If the character 'j' matches the first character of the string 'x', increment 'a'
			if j == rune(x[0]) {
				a++
			} else if j == rune(x[1]) { // If the character 'j' matches the second character of the string 'x', increment 'b'
				b++
			} else { // If the current character 'j' does not match any character in the string 'x'
				ans += min(a, b)
				a, b = 0, 0
			}
		}

		// Add the minimum of 'a' and 'b' to the answer variable 'ans' after the inner loop completes
		ans += min(a, b)
	}

	// Print the final answer
	fmt.Println(ans)
}

// Helper function to return the minimum of two integers
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// <END-OF-CODE>
