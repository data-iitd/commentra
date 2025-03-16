package main

import (
	"fmt"
)

func main() {
	// Declare a variable to hold the input number
	var n int
	
	// Read the input number from the user
	fmt.Scan(&n)
	
	// Initialize a flag to indicate if a solution is found
	flg := false
	
	// Check if the input number is less than 4
	if n < 4 {
		// If n is less than 4, output "No" since it's not possible to form n with 4s and 7s
		fmt.Println("No")
	} else {
		// Iterate through possible counts of 4s (i)
		for i := 0; i <= (n / 4); i++ {
			// Iterate through possible counts of 7s (j)
			for j := 0; j <= (n / 7); j++ {
				// Check if the current combination of 4s and 7s equals n
				if (i * 4 + j * 7) == n {
					// If a valid combination is found, set the flag to true
					flg = true
					break // Exit the inner loop
				}
			}
			// If a valid combination has been found, exit the outer loop
			if flg {
				break
			}
		}
		
		// Check if a valid combination was found
		if flg {
			// Output "Yes" if a combination of 4s and 7s can form n
			fmt.Println("Yes")
		} else {
			// Output "No" if no combination can form n
			fmt.Println("No")
		}
	}
}

