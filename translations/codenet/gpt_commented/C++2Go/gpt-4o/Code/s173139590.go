package main

import (
	"fmt"
)

func main() {
	// Declare a variable to hold the number of submissions
	var n int
	// Read the number of submissions from the user
	fmt.Scan(&n)

	// Initialize counters for different result types
	acCount := 0 // Count of Accepted submissions
	waCount := 0 // Count of Wrong Answer submissions
	tleCount := 0 // Count of Time Limit Exceeded submissions
	reCount := 0 // Count of Runtime Error submissions

	// Loop through each submission
	for i := 0; i < n; i++ {
		var s string // Variable to hold the result of the current submission
		// Read the result of the current submission
		fmt.Scan(&s)

		// Increment the respective counter based on the result
		switch s {
		case "AC":
			acCount++ // Increment Accepted count
		case "WA":
			waCount++ // Increment Wrong Answer count
		case "TLE":
			tleCount++ // Increment Time Limit Exceeded count
		case "RE":
			reCount++ // Increment Runtime Error count
		}
	}

	// Output the counts of each result type
	fmt.Printf("AC x %d\n", acCount) // Display Accepted count
	fmt.Printf("WA x %d\n", waCount) // Display Wrong Answer count
	fmt.Printf("TLE x %d\n", tleCount) // Display Time Limit Exceeded count
	fmt.Printf("RE x %d\n", reCount) // Display Runtime Error count
}

// <END-OF-CODE>
