package main

import (
	"fmt"
)

func main() {
	// Declare a variable to hold the input string
	var s string
	
	// Read input from the user and store it in the variable 's'
	fmt.Scan(&s)
	
	// Check if the length of the string is at least 4 characters 
	// and if the first four characters are "YAKI"
	if len(s) >= 4 && s[0:4] == "YAKI" {
		// If the condition is true, print "Yes"
		fmt.Println("Yes")
	} else {
		// If the condition is false, print "No"
		fmt.Println("No")
	}
}
