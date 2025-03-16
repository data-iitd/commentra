package main

import (
	"fmt"
)

func main() {
	var S int // Declare an integer variable named S

	// Read an integer value from the standard input
	fmt.Scan(&S)

	// Check if the value of S is less than 60
	if S < 60 {
		// If the condition is true, print the time in the format "0:0:S"
		fmt.Printf("0:0:%d\n", S)
	} else if S < 3600 { // Else if the value of S is less than 3600 (1 hour)
		// Print the time in the format "0:M:S"
		fmt.Printf("0:%d:%d\n", S/60, S%60)
	} else { // Else if the value of S is greater than or equal to 3600
		// Print the time in the format "H:M:S"
		fmt.Printf("%d:%d:%d\n", S/3600, (S%3600)/60, S%60)
	}
}

// <END-OF-CODE>
