package main

import (
	"fmt"
)

func main() {
	// Declare variables to hold marks for midterm, final, and retake
	var m, f, r int

	// Continuously read input until the termination condition is met
	for {
		_, err := fmt.Scan(&m, &f, &r)
		if err != nil || (m == -1 && f == -1 && r == -1) {
			break // Exit the loop if input fails or termination condition is met
		}

		// Check if either midterm or final score is -1, indicating failure
		if m == -1 || f == -1 {
			fmt.Println("F") // Output "F" for failure
		} else if m+f >= 80 {
			fmt.Println("A") // Output "A" for excellent performance
		} else if m+f >= 65 {
			fmt.Println("B") // Output "B" for good performance
		} else if m+f >= 50 || r >= 50 {
			fmt.Println("C") // Output "C" for satisfactory performance
		} else if m+f >= 30 {
			fmt.Println("D") // Output "D" for passing but needs improvement
		} else {
			fmt.Println("F") // Output "F" for failure
		}
	}
}

// <END-OF-CODE>
