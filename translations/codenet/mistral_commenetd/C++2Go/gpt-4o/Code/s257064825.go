package main

import (
	"fmt"
)

func main() {
	// Read input string from standard input
	var str string
	fmt.Scan(&str)

	// Initialize sum variable to 0
	sum := int64(0)

	// Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
	for _, x := range str {
		sum += int64(x - '0') // Subtract '0' to convert rune value of digit character to its integer value
	}

	// Check if sum is divisible by 9
	if sum%9 == 0 {
		fmt.Println("Yes") // Output "Yes" if sum is divisible by 9
	} else {
		fmt.Println("No") // Output "No" otherwise
	}
}

// <END-OF-CODE>
