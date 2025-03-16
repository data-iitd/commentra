package main

import (
	"fmt"
)

func main() {
	var n int // Declare an integer variable to store the number of test cases
	fmt.Scan(&n) // Read the value of n from the standard input

	acCount := 0 // Initialize an integer variable to count AC submissions
	waCount := 0 // Initialize an integer variable to count WA submissions
	tleCount := 0 // Initialize an integer variable to count TLE submissions
	reCount := 0 // Initialize an integer variable to count RE submissions

	// Loop through each test case
	for i := 0; i < n; i++ {
		var s string // Declare a string variable to store the result of a test case
		fmt.Scan(&s) // Read the result from the standard input
		if s == "AC" { // Check if the result is AC
			acCount++ // Increment the AC count
		} else if s == "WA" { // Check if the result is WA
			waCount++ // Increment the WA count
		} else if s == "TLE" { // Check if the result is TLE
			tleCount++ // Increment the TLE count
		} else if s == "RE" { // Check if the result is RE
			reCount++ // Increment the RE count
		}
	}

	// Print the counts of each result type
	fmt.Printf("AC x %d\n", acCount)
	fmt.Printf("WA x %d\n", waCount)
	fmt.Printf("TLE x %d\n", tleCount)
	fmt.Printf("RE x %d\n", reCount)
}

// <END-OF-CODE>
