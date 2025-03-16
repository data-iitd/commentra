package main

import (
	"fmt"
)

func main() {
	// Optimize input/output operations
	var str string
	// Read the input string from the user
	fmt.Scan(&str)

	// Initialize a variable to hold the sum of digits
	sum := 0

	// Iterate through each character in the string
	for _, x := range str {
		// Convert character to integer and add to sum
		sum += int(x - '0') // '0' is the rune for character '0'
	}

	// Check if the sum of digits is divisible by 9
	if sum%9 == 0 {
		// If divisible, print "Yes"
		fmt.Println("Yes")
	} else {
		// If not divisible, print "No"
		fmt.Println("No")
	}
}

// <END-OF-CODE>
