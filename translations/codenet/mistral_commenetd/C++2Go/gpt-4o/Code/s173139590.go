package main

import (
	"fmt"
)

func main() {
	// Initialize variables to store the number of each contest result
	var n int // number of contest results to be read
	var acCount, waCount, tleCount, reCount int // counters for each result type

	// Read the number of contest results from the standard input
	fmt.Scan(&n)

	// Read each contest result and update the corresponding counter
	for i := 0; i < n; i++ {
		var result string // string to store the contest result (AC, WA, TLE, or RE)
		fmt.Scan(&result)
		switch result {
		case "AC": // if the contest result is AC
			acCount++ // increment the number of AC results
		case "WA": // if the contest result is WA
			waCount++ // increment the number of WA results
		case "TLE": // if the contest result is TLE
			tleCount++ // increment the number of TLE results
		case "RE": // if the contest result is RE
			reCount++ // increment the number of RE results
		}
	}

	// Print the number of each contest result to the standard output
	fmt.Printf("AC x %d\n", acCount)
	fmt.Printf("WA x %d\n", waCount)
	fmt.Printf("TLE x %d\n", tleCount)
	fmt.Printf("RE x %d\n", reCount)
}

// <END-OF-CODE>
