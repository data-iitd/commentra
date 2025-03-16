package main

import (
	"fmt"
)

func main() {
	var n, k int
	var a string

	fmt.Scan(&n) // Reading the first integer input from the user
	fmt.Scan(&k) // Reading the second integer input from the user
	fmt.Scan(&a) // Reading the string input from the user

	if k > n/2 { // Check if k is greater than n/2
		for k < n { // If true, print "RIGHT" until k equals n
			fmt.Println("RIGHT")
			k++
		}
	} else { // Else if k is less than n/2
		for k > 1 { // Print "LEFT" until k equals 1
			fmt.Println("LEFT")
			k--
		}
	}

	if k == 1 { // If k equals 1
		for i := 0; i < len(a); i++ { // Iterate through each character in the string
			fmt.Println("PRINT", string(a[i])) // Print the character
			if (i + 1) < len(a) { // If the index is not the last one
				fmt.Println("RIGHT") // Print "RIGHT"
			}
		}
	} else { // Else if k is not equal to 1
		for i := len(a) - 1; i >= 0; i-- { // Iterate through each character in reverse order
			fmt.Println("PRINT", string(a[i])) // Print the character
			if (i - 1) >= 0 { // If the index is not the first one
				fmt.Println("LEFT") // Print "LEFT"
			}
		}
	}
}

// <END-OF-CODE>
