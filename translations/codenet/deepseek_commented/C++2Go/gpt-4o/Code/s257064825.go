package main

import (
	"fmt"
)

func main() {
	var str string // Declare a string variable to store input
	fmt.Scan(&str) // Read input string

	sum := 0 // Initialize sum variable to store the sum of digits
	for _, x := range str { // Iterate over each character in the string
		sum += int(x - '0') // Convert character to integer and add to sum
	}

	if sum%9 == 0 { // Check if sum is divisible by 9
		fmt.Println("Yes") // Print "Yes" if sum is divisible by 9
	} else { // Otherwise
		fmt.Println("No") // Print "No"
	}
}

// <END-OF-CODE>
