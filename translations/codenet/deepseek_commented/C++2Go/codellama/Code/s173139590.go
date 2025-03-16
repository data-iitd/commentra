package main

import (
	"fmt"
	"os"
)

func main() {
	var n int // Declare an integer variable to store the number of test cases
	fmt.Scan(&n) // Read the value of n from the standard input

	var ac_count int = 0 // Initialize an integer variable to count AC submissions
	var wa_count int = 0 // Initialize an integer variable to count WA submissions
	var tle_count int = 0 // Initialize an integer variable to count TLE submissions
	var re_count int = 0 // Initialize an integer variable to count RE submissions

	// Loop through each test case
	for i := 0; i < n; i++ {
		var s string // Declare a string variable to store the result of a test case
		fmt.Scan(&s) // Read the result from the standard input
		if s == "AC" { // Check if the result is AC
			ac_count += 1 // Increment the AC count
		} else if s == "WA" { // Check if the result is WA
			wa_count += 1 // Increment the WA count
		} else if s == "TLE" { // Check if the result is TLE
			tle_count += 1 // Increment the TLE count
		} else if s == "RE" { // Check if the result is RE
			re_count += 1 // Increment the RE count
		}
	}

	// Print the counts of each result type
	fmt.Printf("AC x %d\n", ac_count)
	fmt.Printf("WA x %d\n", wa_count)
	fmt.Printf("TLE x %d\n", tle_count)
	fmt.Printf("RE x %d\n", re_count)
}

