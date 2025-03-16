package main

import (
	"fmt"
)

func main() {
	var n, k int
	var a string

	// Reading two integers n and k from user input
	fmt.Scan(&n, &k)
	// Reading a string a from user input
	fmt.Scan(&a)

	// Check if k is greater than half of n
	if k > n/2 {
		// If true, move to the right until k equals n
		for k < n {
			fmt.Println("RIGHT") // Output "RIGHT" for each step to the right
			k++                   // Increment k
		}
	} else {
		// If false, move to the left until k equals 1
		for k > 1 {
			fmt.Println("LEFT") // Output "LEFT" for each step to the left
			k--                 // Decrement k
		}
	}

	// If k equals 1, print the characters of the string from left to right
	if k == 1 {
		for i := 0; i < len(a); i++ {
			fmt.Println("PRINT", string(a[i])) // Print the current character
			// If not at the last character, output "RIGHT"
			if (i + 1) < len(a) {
				fmt.Println("RIGHT")
			}
		}
	} else {
		// If k is not 1, print the characters of the string from right to left
		for i := len(a) - 1; i >= 0; i-- {
			fmt.Println("PRINT", string(a[i])) // Print the current character
			// If not at the first character, output "LEFT"
			if (i - 1) >= 0 {
				fmt.Println("LEFT")
			}
		}
	}
}

// <END-OF-CODE>
