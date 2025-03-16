package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// Declare a variable to hold the number of submissions
	var n int
	// Read the number of submissions from the user
	fmt.Scan(&n)

	// Initialize counters for different result types
	var acCount, waCount, tleCount, reCount int

	// Create a new scanner to read input
	scanner := bufio.NewScanner(os.Stdin)

	// Loop through each submission
	for i := 0; i < n; i++ {
		// Read the result of the current submission
		scanner.Scan()
		s := scanner.Text()

		// Increment the respective counter based on the result
		if strings.EqualFold(s, "AC") {
			acCount += 1 // Increment Accepted count
		} else if strings.EqualFold(s, "WA") {
			waCount += 1 // Increment Wrong Answer count
		} else if strings.EqualFold(s, "TLE") {
			tleCount += 1 // Increment Time Limit Exceeded count
		} else if strings.EqualFold(s, "RE") {
			reCount += 1 // Increment Runtime Error count
		}
	}

	// Output the counts of each result type
	fmt.Printf("AC x %d\n", acCount) // Display Accepted count
	fmt.Printf("WA x %d\n", waCount) // Display Wrong Answer count
	fmt.Printf("TLE x %d\n", tleCount) // Display Time Limit Exceeded count
	fmt.Printf("RE x %d\n", reCount) // Display Runtime Error count
}

