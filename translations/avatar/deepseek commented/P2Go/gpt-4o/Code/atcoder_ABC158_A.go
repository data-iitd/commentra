package main

import (
	"fmt"
	"strings"
)

func main() {
	var stdin string // Declare a variable to store user input
	fmt.Scanln(&stdin) // Take input from the user and store it in the variable stdin

	s := stdin // Assign the input to the variable s

	// Check if the string s contains both "A" and "B"
	if strings.Contains(s, "A") && strings.Contains(s, "B") {
		fmt.Println("Yes") // If both "A" and "B" are in the string, print "Yes"
	} else {
		fmt.Println("No") // Otherwise, print "No"
	}
} // End of main function
// <END-OF-CODE>
