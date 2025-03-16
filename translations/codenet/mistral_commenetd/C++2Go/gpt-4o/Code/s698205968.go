package main // Declare the main package

import (
	"fmt" // Import the fmt package for input/output operations
)

func main() { // Beginning of the main function
	var m, f, r int // Declare variables m, f, and r to store user input

	for { // Start of an infinite loop
		_, err := fmt.Scan(&m, &f, &r) // Read input values for m, f, and r
		if err != nil { // Check for input errors
			break // Exit the loop if there is an error
		}

		if m == -1 || f == -1 { // Check if m or f is -1
			fmt.Println("F") // If so, print "F" and move on to the next input
			continue
		}

		if m+f >= 80 { // Check if the sum of m and f is greater than or equal to 80
			fmt.Println("A") // If so, print "A" and move on to the next input
			continue
		}

		if m+f >= 65 { // Check if the sum of m and f is greater than or equal to 65
			fmt.Println("B") // If so, print "B" and move on to the next input
			continue
		}

		if m+f >= 50 || r >= 50 { // Check if the sum of m and f is greater than or equal to 50
			// or if r is greater than or equal to 50
			fmt.Println("C") // If so, print "C" and move on to the next input
			continue
		}

		if m+f >= 30 { // Check if the sum of m and f is greater than or equal to 30
			fmt.Println("D") // If so, print "D" and move on to the next input
			continue
		}

		fmt.Println("F") // If none of the above conditions are met, print "F" and move on to the next input
	}
}

// <END-OF-CODE>
